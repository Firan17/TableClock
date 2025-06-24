#pragma once

#include <Arduino.h>
#include <GyverBME280.h>
#include <GyverDS3231.h>
#include "PhotoSensor.h"
#include <GTimer.h>

GyverBME280 bmp;
GyverDS3231 rtc;
PhotoSensor photo(PHOTO, BRIGHT_THRESHOLD);
Datime dt;

GTimerCb16<millis> _dt_sync_;
GTimerCb16<millis> _point_upd_;

// ===== ФУНКЦИИ ДАТЧИКОВ =====
float readTemp() {
    bmp.oneMeasurement();
    while (bmp.isMeasuring());
    return bmp.readTemperature();
}

// ===== ФУНКЦИИ ТАЙМЕРОВ =====
void dt_sync() { 
    dt = rtc; 
    //disp.setCursor(0);
    //disp.print(dt.second % 10);
    //disp.update();
    if (photo.isDark()) PWM_20KHZ_D3(200);
    else PWM_20KHZ_D3(0); 
}

void point_update() {
    //disp.point(0, !point);
    //disp.update();
    //point = !point;
}

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
    _dt_sync_.startInterval(MS_01S, dt_sync);
    _point_upd_.startInterval(MS_500, point_update);
    
}