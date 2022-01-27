#include <Arduino.h>
#include "RF24Service.h"

// Remove, when built for production
#define SHOW_DEBUG

RF24Service radio(10, 9);
byte request[8];

void setup() {
  Serial.begin(9600);

  // #begin Init nrf24 as resiever ----------------------------/
  #ifdef SHOW_DEBUG
  radio.showDebug();
  #endif
  radio.init(RF24_PA_MAX, RF24_1MBPS, sizeof(request));
  radio.asReciever();
  // #end Init nrf24 as resiever ------------------------------/

  // #todo init Motors
}

void loop() {
  // #begin Get data from nrf24 -------------------------------/
  byte pipeId = 255;
  while (radio.available(&pipeId)) {
    byte payloadSize = radio.getPayloadSize();
    radio.read(&request, payloadSize);
  }
  bool isNoData = pipeId == 255;
  // #end Get data from nrf24 ---------------------------------/

  if (!isNoData) {
    // #todo map nrf data

    // #todo pass mapped data to motors

    // #todo_optional get battery info via currency devider
    // #rodo_optional send battery info back to controller
  }

  delay(1000);
}