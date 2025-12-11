#include "filter_functions.h"
#include "constants.h"
#include <iostream>

using namespace std;

// Функция фильтрации
WindRecord** filterRecords(
    WindRecord* array[],
    int size,
    bool (*check)(WindRecord* element),
    int& result_size
) {
    // Временный массив для результатов
    WindRecord** tempResult = new WindRecord*[size];
    result_size = 0;
    
    // Перебираем все элементы
    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            tempResult[result_size] = array[i];
            result_size++;
        }
    }
    
    // Создаём итоговый массив нужного размера
    WindRecord** result = new WindRecord*[result_size];
    for (int i = 0; i < result_size; i++) {
        result[i] = tempResult[i];
    }
    
    delete[] tempResult;
    return result;
}

// 1. Функция отбора: западный ветер
bool checkWestWind(WindRecord* element) {
    return element->direction == WindDirection::West;
}

// 2. Функция отбора: скорость > 5 м/с
bool checkHighSpeed(WindRecord* element) {
    return element->speed > HIGH_SPEED_THRESHOLD;
}