#ifndef PhotoSensor_h
#define PhotoSensor_h

#include <Arduino.h>

class PhotoSensor {

    public:
        PhotoSensor(uint8_t PIN);                       // конструктор
        PhotoSensor(uint8_t PIN, uint16_t THRESHOLD);   // конструктор
        ~PhotoSensor();                                 // деструктор
        uint16_t readBrightness();                      // получаем уровень освещённости
        void setThreshold(uint16_t THRESHOLD);          // установка нового порога освещённости
        bool isBright();                                // освещено (выше порога)
        bool isDark();                                  // темно (ниже порога)

    private:
        uint8_t _pin;                                   // пин подключения сенсора
        uint16_t _bright;                               // текущий уровень освещенности
        uint16_t _threshold = 150;                      // пороговый уровень освещенности

};

PhotoSensor::PhotoSensor(uint8_t PIN) {
    _pin = PIN;
    pinMode(_pin, INPUT);
}

PhotoSensor::PhotoSensor(uint8_t PIN, uint16_t THRESHOLD) {
    _pin = PIN;
    _threshold = THRESHOLD;
    pinMode(_pin, INPUT);
}

PhotoSensor::~PhotoSensor() {
}

uint16_t PhotoSensor::readBrightness() {
    _bright = constrain(analogRead(_pin), 0, 1024);
    //_bright = analogRead(_pin);
    return _bright;
}

void PhotoSensor::setThreshold(uint16_t THRESHOLD) {
    _threshold = THRESHOLD;
}

bool PhotoSensor::isBright() {
    readBrightness();
    return (_bright > _threshold) ? 1 : 0;
}

bool PhotoSensor::isDark() {
    readBrightness();
    return (_bright <= _threshold) ? 1 : 0;
}

#endif