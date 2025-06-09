#pragma once

#define PROJECT_VER "0.0.1"
#define PROJECT_NAME "TableClock"

// управление яркостью
#define BRIGHT_CONTROL 1        // 0/1 - запретить/разрешить управление яркостью (при отключении яркость всегда будет макс.)
#define BRIGHT_THRESHOLD 150    // величина сигнала, ниже которой яркость переключится на минимум (0-1023)

// пины
#define LED_PIN D13
#define PHOTO 2
