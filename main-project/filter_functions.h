#ifndef FILTER_FUNCTIONS_H
#define FILTER_FUNCTIONS_H

#include "wind_record.h"

// Прототип функции фильтрации
WindRecord** filterRecords(
    WindRecord* array[],
    int size,
    bool (*check)(WindRecord* element),
    int& result_size
);

// Прототипы функций отбора для вашего варианта
bool checkWestWind(WindRecord* element);      // 1. Западный ветер
bool checkHighSpeed(WindRecord* element);     // 2. Скорость > 5 м/с

#endif