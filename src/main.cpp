#include <Arduino.h>

#include <GyverPWM.h>

#include "config.h"
#include <GyverSegment.h>

Disp595Static<4> disp(DAT_595, CLK_595, CS_595);
bool point = 0;


#include "sensors.h"


void setup() {
  pinMode(EO_595, OUTPUT);
  digitalWrite(EO_595, 0);

  Serial.begin(115200);
  Serial.println("\n" PROJECT_NAME " v" PROJECT_VER);
  PINS_SET();
  sensors_begin();

  disp.setCursor(0);
  disp.print("hello");
  disp.update();
  delay(1000);
  disp.setCursor(0);
  disp.print(8);
  disp.point(0, 1);
  disp.update();          

}

void loop() {
  
  _dt_sync_.tick();
  _point_upd_.tick();

  if (rtc.tick()) {

    Serial.print("Temperature: ");
    Serial.print(readTemp());
    Serial.println(" *C");

    Serial.println(dt.toString());

    Serial.print("Brightness: ");
    Serial.print(photo.readBrightness());
    Serial.print(" ");
    if (photo.isBright()) Serial.println("Bright!");
    else Serial.println("Dark!");

  }
}
