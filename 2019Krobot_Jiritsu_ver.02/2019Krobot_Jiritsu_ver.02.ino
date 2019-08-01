//2019年　課題ロボット　自律型ロボット用プログラム

//team name: AYS(仮)
//robot name: ときのすけ

//version: 01
//last update: 2019/07/30
//author: 竹澤　慎悟
//      : 堅持　晃

//board type: Arduino Mega
//CPU type: ATmega2560

//---description:
//  製品版リリースです
//  予選パターンを中心にプログラムを書き進めていく所存

//---update log
//2019/06/15:vacuum関数とUI処理の追加
//           変数vacuumrangeの追加
//    6月中旬:距離センサと光センサの組み合わせによる壁検知処理の追加
//           それに伴うUI処理の変更・追加
//    6月下旬:ボールの振り落とし処理の追加
//    7月中旬:床の黒線用センサー追加
//       下旬:New基盤に換装
//            リセットボタン押すと左下のモーターが回る(13番ピンが原因)
//              →ピンの位置を変更
/***************************************************/

//include header file
#include "Krobot_J01_h.h"
#include "Krobot_J01_s.h"

//switch用関数
int mode_run = 0;

//コートの選択用変数
byte select = 0x0F;

//version string
const char VERSION[4] = "02";

//low battery voltage threshold
const float BAT_COM_LOW = 6.2;
const float BAT_MOTOR_LOW = 3.4 * 3; //10.2V

struct romdata {
  int motorrange_l;
  int motorrange_r;
  int backrange_l;
  int backrange_r;
  int vacuumrange;
  int servo_up;
  int servo_down;
  int sensorthreshold_w;
  int sensorthreshold_l;
  boolean patternType;
} value = {
  100, 100,
  100, 100,
  0, 0,
  0, 0,
  0, false
};

//パターンの表示
int pattern_A[16] = { //Aパターン
  0, 1, 2, 3, 4, 5, 6
};

int pattern_B[16] = { //Bパターン
  0, 1, 2, 3, 4, 5, 6
};

/****************************************************************/
void setup() {
  // put your setup code here, to run once:
  //  lcd.kanaOn(); //lcdのカタカナ表示を有効に
  delay(50);
  //initialize
  initPin();
  initLib();
  if (!digitalRead(PIN_SW5)) {
    mode_run = 100;
  }
  bootSplash();
  checkRom();

  myservo.write(value.servo_up); //サーボを規定値まで下げる
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (mode_run) {
    case 0:
    case 100:
      menu(mode_run == 0);  //設定画面に飛ばす
      break;

    //---処理
    case 1: //動作実行画面
      lcd.clear();
      lcd.print("sensor");
      mode_run++;
      break;

    case 2:
      vacuum(100); //バキュームON

      move_pattern();
      lcd.clear();
      lcd.print("good ");
      mode_run++;
      break;

    case 3:

      while (sensorRead_W()) {  //距離センサがTrueである限り動作する
        lcd.clear();
        lcd.print("feel wall ");
        delay(50);
        motor(60, 55,//右壁沿い用直進
              60, 55);
      }
      
      japanSea();
      
      mode_run = 6;
      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
      Serial.println("action end");
      lcd.clear();
      lcd.print("action end");
      motor(0, 0,
            0, 0);
      servoDown();
      mode_run = 7;

      break;

    case 7:
      delay(100);
      vacuum(0);

      int count = 0;
      //ボールの振り落とし
      while (count < 20) {
        motor(-60, 60,
              -60, 60);
        delay(50);

        motor(0, 0,
              0, 0);
        delay(100);

        motor(60, -60,
              60, -60);
        delay(50);

        motor(60, -60,//右平行移
              -60, 60);
        delay(100);
        count++;
      }
      motor(0, 0,
            0, 0);
      delay(100);

      while (analogRead(PIN_SENSOR_W) < 620 ) {
        motor(60, -60,//右平行移
              -60, 60);
      }
      motor(0, 0,
            0, 0);

      mode_run = 0;
      break;


  }
}

/****************************************************/
void initPin() { //ピン定義
  //switch pin
  pinMode(PIN_SW1, INPUT_PULLUP);
  pinMode(PIN_SW2, INPUT_PULLUP);
  pinMode(PIN_SW3, INPUT_PULLUP);
  pinMode(PIN_SW4, INPUT_PULLUP);
  pinMode(PIN_SW5, INPUT_PULLUP);
  //motor pin
  pinMode(PIN_MOTOR_L1_DIR, OUTPUT);
  pinMode(PIN_MOTOR_R1_DIR, OUTPUT);
  pinMode(PIN_MOTOR_L2_DIR, OUTPUT);
  pinMode(PIN_MOTOR_R2_DIR, OUTPUT);
  pinMode(PIN_MOTOR_V1_DIR, OUTPUT);
}

void initLib() {  //各ライブラリの定義まとめ
  //serial port
  Serial.begin(115200); //[bps]
  //LCD
  lcd.begin(16, 2);
  //servo
  myservo.attach(PIN_SERVO);
}

/********************************************************/
int search_SW() { //選択スイッチを読み込む
  for (int i = 3; i >= 0; i--) {
    if (bitRead(select, i)) {
      return i;
    }
  }
  return 0;
}

boolean SW_read(int num) {  //選択スイッチの論理を読み出す
  num = constrain(num, 0, 3); //変数:num 最小値:0 最大値:3
  return bitRead(select, num);
}
