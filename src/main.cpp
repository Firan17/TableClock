#include <Arduino.h>

#include "config.h"
#include "sensors.h"


void setup() {
  Serial.begin(115200);
  Serial.println("\n" PROJECT_NAME " v" PROJECT_VER);
  PINS_SET();
  sensors_begin();
}

void loop() {
  
  _dt_sync_.tick();

  if (rtc.tick()) {

    Serial.print("Temperature: ");
    Serial.print(readTemp());
    Serial.println(" *C");

    Serial.println(dt.toString());

  }
}
