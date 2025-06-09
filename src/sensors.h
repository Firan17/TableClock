#pragma once

#include <GyverBME280.h>
#include <GyverDS3231.h>
GyverBME280 bmp;
GyverDS3231 rtc;
Datime dt;

int readTemp() {
    bmp.oneMeasurement();
    while (bmp.isMeasuring());
    return round(bmp.readTemperature());
}


void sensors_set() {
    
    // фотодиод
    pinMode(PHOTO, INPUT);

    // BMP280
    bmp.setHumOversampling(MODULE_DISABLE);
    bmp.setPressOversampling(MODULE_DISABLE);
    bmp.setMode(FORCED_MODE);
    bmp.begin();

    // однократное измерение температуры
    readTemp();
  
    // DS3231
    rtc.setPeriod(3600);
    rtc.begin();

    Serial.print("RTC: ");
    Serial.println(rtc.isOK());

    Serial.print("RTC Reset: ");
    Serial.println(rtc.isReset());

    //rtc.setBuildTime();

    // был сброс питания RTC, время некорректное
    if (rtc.isReset()) rtc.setBuildTime();     // установить время компиляции прошивки

}