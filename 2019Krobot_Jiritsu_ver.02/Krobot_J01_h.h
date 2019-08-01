//%%%Kadai robot 2019%%%///
//header file for hardware

//last update: 2019/06/06
//version: beta
//author: shingo takesawa
//      : (ほかに編集者がいればここに書く)

#ifndef Krobot_J01_h_h
#define Krobot_J01_h_h

//---define pins

//LCD
#define PIN_LCD_RS 48
#define PIN_LCD_RW 43
#define PIN_LCD_EN 42
#define PIN_LCD_D4 41
#define PIN_LCD_D5 40
#define PIN_LCD_D6 39
#define PIN_LCD_D7 38

//user switch
#define PIN_SW1 53
#define PIN_SW2 52
#define PIN_SW3 51
#define PIN_SW4 50
#define PIN_SW5 49

//servo 
#define PIN_SERVO 45

//sensor pin
#define PIN_SENSOR_W A12 //壁用
#define PIN_SENSOR_L A0  //光用

//battery sens pin
const int PIN_BAT_COM = A13;
const int PIN_BAT_M0 = A14;
const int PIN_BAT_M1 = A15;

//buzzer
const int PIN_BZ = 47;

//motor pins define
const int PIN_MOTOR_R1_DIR = 30; //右モータ
const int PIN_MOTOR_R1_PWM = 10;
const int PIN_MOTOR_L1_DIR = 31; //左モータ
const int PIN_MOTOR_L1_PWM = 11;

const int PIN_MOTOR_R2_DIR = 26; //右モータ2
const int PIN_MOTOR_R2_PWM = 6;
const int PIN_MOTOR_L2_DIR = 27; //左モータ2
const int PIN_MOTOR_L2_PWM = 7;

const int PIN_MOTOR_V1_DIR = 28; //バキュームモータ
const int PIN_MOTOR_V1_PWM = 8;

#endif  //end of KROBOT_R01_h_h
