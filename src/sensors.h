#pragma once

#include <Arduino.h>
#include <GyverBME280.h>
#include <GyverDS3231.h>
#include <GTimer.h>

GyverBME280 bmp;
GyverDS3231 rtc;
Datime dt;

GTimerCb16<millis> _dt_sync_;

// ===== ФУНКЦИИ ДАТЧИКОВ =====
float readTemp() {
    bmp.oneMeasurement();
    while (bmp.isMeasuring());
    return bmp.readTemperature();
}

// ===== ФУНКЦИИ ТАЙМЕРОВ =====
void dt_sync() { dt = rtc; }


// ===== СТАНДАРТНЫЕ ФУНКЦИИ =====
void sensors_set() {
    
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

    // был сброс питания RTC, время некорректное
    if (rtc.isReset()) rtc.setBuildTime();     // установить время компиляции прошивки

    dt = rtc;   // выводим в Datime
}

void sensors_begin(){

    sensors_set();

    // запускаем таймеры

    // синхронизация datime
    _dt_sync_.startInterval(1000, dt_sync);

    
}