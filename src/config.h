#pragma once

#define PROJECT_VER "0.0.1"
#define PROJECT_NAME "TableClock"

// управление яркостью
#define BRIGHT_CONTROL 1        // 0/1 - запретить/разрешить управление яркостью (при отключении яркость всегда будет макс.)
#define BRIGHT_THRESHOLD 150    // величина сигнала, ниже которой яркость переключится на минимум (0-1023)

// пины
#define LED_PIN D13
#define PHOTO 20    // A6

// 74hc595
#define QNT_595 4   // число регистров
#define CLK_595 13
#define CS_595 9
#define DAT_595 11
#define EO_595 7

// Временные константы
#define MS_250         250
#define MS_500         500
#define MS_01S        1000
#define MS_02S        2000
#define MS_05S        5000
#define MS_10S       10000
#define MS_13S       13000
#define MS_15S       15000
#define MS_17S       17000
#define MS_20S       20000
#define MS_30S       30000
#define MS_40S       40000
#define MS_45S       45000
#define MS_50S       50000
#define MS_01M       60000
#define MS_03M      180000
#define MS_05M      300000
#define MS_01H     3600000
#define MS_02H     7200000
#define MS_03H    10800000
#define MS_06H    21600000
#define MS_12H    43200000
#define MS_01D    86400000
#define MS_07D   604800000


void PINS_SET() {}