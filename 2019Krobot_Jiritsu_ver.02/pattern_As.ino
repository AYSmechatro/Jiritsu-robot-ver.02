void pattern_A1() { //pattern A1
  int L_sensor;
  int old_L_sensor;
  int count_L = 0;

  //debug
  Serial.println("Pattern A1");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A1");

  //直進時の黒線検知
  while (count_L < 3) {
    //L_sensor = analogRead(PIN_SENSOR_L);
    if (sensorRead_L()) {
      count_L++;
    } else {
      motor(60, 60,//直進
            60, 60);
    }
    delay(10);
    //old_L_sensor = L_sensor;
  }

  motor(0, 0,
        0, 0);
  delay(200);

  //後進時の黒線検知
  count_L = 0;
  while (count_L < 2) {
    //L_sensor = analogRead(PIN_SENSOR_L);
    if (sensorRead_L()) {
      count_L++;
    } else {
      motor(-60, -58,//後進
            -60, -58);
    }
    delay(10);
    //old_L_sensor = L_sensor;
  }

  motor(-60, -58,//後進
        -60, -58);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(200);

  motor(-60, 60,
        -60, 60);//90度回転
  delay(600);

  motor(0, 0,
        0, 0);
  delay(200);

  motor(-60, 60,//左平行移動
        60, -60);
  delay(300);

  motor(0, 0,
        0, 0);
  delay(200);

  //直進時の黒線検知
  count_L = 0;
  while (count_L < 3) {
    //L_sensor = analogRead(PIN_SENSOR_L);
    if (sensorRead_L()) {
      count_L++;
    } else {
      motor(60, 60,//直進
            60, 60);
    }
    delay(10);
    //old_L_sensor = L_sensor;
  }

  motor(60, 60,//直進
        60, 60);
  delay(200);

  motor(0, 0,
        0, 0);
  delay(200);

  //後進時の黒線検知
  count_L = 0;
  while (count_L < 2) {
    //L_sensor = analogRead(PIN_SENSOR_L);
    if (sensorRead_L()) {
      count_L++;
    } else {
      motor(-60, -58,//後進
            -60, -58);
    }
    delay(10);
    //old_L_sensor = L_sensor;
  }

  motor(0, 0,
        0, 0);
  delay(200);

  //右移動
  count_L = 0;
  while (count_L < 2) {
    L_sensor = analogRead(PIN_SENSOR_L);
    if (L_sensor > 50 && old_L_sensor < 50) {
      count_L++;
    } else {
      motor(60, -60,//右平行移動
            -60, 60);
    }
    delay(10);
    //old_L_sensor = L_sensor;
  }

  motor(0, 0,
        0, 0);
  delay(200);

  //直進時の黒線検知
  count_L = 0;
  while (count_L < 2) {
    //L_sensor = analogRead(PIN_SENSOR_L);
    if (sensorRead_W()) {
      count_L++;
    } else {
      motor(60, 60,//直進
            60, 60);
    }
    delay(10);
    //old_L_sensor = L_sensor;
  }

  motor(0, 0,
        0, 0);
  delay(200);

  while (sensorRead_W()) {
    motor(60, -60,//右平行移
          -60, 60);
  }
  motor(0, 0,
        0, 0);
  delay(200);
}

void pattern_A2() {
  //debug
  Serial.println("Pattern A2");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A2");

  //このディレイ　パターン書くときは消しておく
  delay(5000);
}

void pattern_A3() {
  //debug
  Serial.println("Pattern A3");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A3");

  //このディレイ　パターン書くときは消しておく
  delay(5000);
}

void pattern_A4() {
  //debug
  Serial.println("Pattern A4");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A4");

  //このディレイ　パターン書くときは消しておく
  delay(5000);
}

void pattern_A5() {
  //debug
  Serial.println("Pattern A5");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A5");

  //このディレイ　パターン書くときは消しておく
  delay(5000);
}

void pattern_A6() {
  //debug
  Serial.println("Pattern A6");
  lcd.setCursor(1, 1);
  lcd.print("Pattern A6");

  //このディレイ　パターン書くときは消しておく
  delay(5000);
}
