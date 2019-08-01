void japanSea() { //日本海エリアの動作です
  Serial.println("japan sea mode");
  lcd.clear();
  lcd.print("japan sea");

  motor(60, 60,//直進
        60, 60);
  delay(1000);

  motor(0, 0,//
        0, 0);
  delay(100);

  motor(60, -60,//右平行移動
        -60, 60);
  delay(1250);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, -60,
        60, -60);//180度回転
  delay(1100);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, 60,//直進
        60, 60);
  delay(1600);

  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 600 ) {
    motor(60, -60,//右平行移
          -60, 60);
  }
  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) > 430 ) {
    motor(-60, 60,//左平行移動
          60, -60);
  }
  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, 60,//直進
        60, 60);
  delay(1600);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, -60,
        60, -60);//180度回転
  delay(1100);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(-60, 60,//左平行移動
        60, -60);
  delay(700);

  motor(0, 0,
        0, 0);
  delay(100);

  motor(60, 60,//直進
        60, 60);
  delay(4700);

  motor(0, 0,
        0, 0);
  delay(100);
  
  while (analogRead(PIN_SENSOR_W) < 600 ) {
    motor(60, -60,//右平行移動
          -60, 60);
  }
  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) > 120) {
    motor(-80, -80,//後進
          -80, -80);
  }
  motor(-80, -80,
        -80, -80);
  delay(145);

  //vacuum(0); //右平行移動前にバキュームを止める
  motor(0, 0,
        0, 0);
  delay(100);

  while (analogRead(PIN_SENSOR_W) < 620 ) {
    motor(60, -60,//右平行移動
          -60, 60);
  }
  motor(0, 0,
        0, 0);
  delay(100);

  motor(-60, 60,//左平行移動
        60, -60);
  delay(30);

  motor(0, 0,
        0, 0);
  delay(100);



}
