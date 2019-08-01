//sensor process

//get battery voltage[V(float)]
float batteryRead(byte pin) {
  float volt = (float)analogRead(pin) / 1023.0 * 20.1515;
  //if (pin == PIN_BAT_COM) volt += 0.7;
  return volt;
}


//検出時true
boolean sensorRead_W() {
  return (analogRead(PIN_SENSOR_W) < value.sensorthreshold_w);
}

boolean sensorRead_L(){
 return (analogRead(PIN_SENSOR_L) < value.sensorthreshold_l);
}  


  //去年のもの
  //return (anzalogRead(PIN_SENSOR) < value.sensorthreshold_b);
  //return (analogRead(PIN_SENSOR) < value.sensorthreshold_w);
