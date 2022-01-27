#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  // #init NRF24

  // #init Motors
}

void loop() {
  // #get data from nrf

  // #if no data got from nrf, then skip other steps

  // #map nrf data

  // #pass mapped data to motors

  // #optional get battery info via currency devider
  // #optional send battery info back to controller

  Serial.println(micros());
  delay(1000);
}