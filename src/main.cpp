#include <Arduino.h>

#include "config.h"
#include "sensors.h"


void setup() {
  Serial.begin(115200);
  Serial.println("\n" PROJECT_NAME " v" PROJECT_VER);
  sensors_set();
}

void loop() {
  


  if (rtc.tick()) {
    Datime dt = rtc;

  Serial.print("Temperature: ");
  Serial.print(readTemp());
  Serial.println(" *C");

  
  Serial.print("Date: ");
  Serial.print(dt.day);
  Serial.print(".");
  Serial.print(dt.month);
  Serial.print(".");
  Serial.println(dt.year);

  Serial.print("Time: ");
  Serial.print(dt.hour);
  Serial.print(":");
  Serial.print(dt.minute);
  Serial.print(":");
  Serial.println(dt.second);

  Serial.println(rtc.getTime().toString());

  }
}
