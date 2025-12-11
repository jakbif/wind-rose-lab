#include <iostream>
#include <fstream>
#include <string>
#include "wind_record.h"
#include "constants.h"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "Лабораторная работа: Роза ветров" << endl;
    cout << "Вариант №6" << endl;
    cout << "Выполнил: [Ваше Имя]" << endl;
    cout << "==========================================" << endl << endl;
    
    
    cout << "Тестирование структур данных:" << endl;
    
  
    WindRecord testRecord(15, 3, 2024, WindDirection::West, 6.8);
    
    cout << "Тестовая запись создана:" << endl;
    cout << "Дата: " << testRecord.date.day << "." 
         << testRecord.date.month << "." 
         << testRecord.date.year << endl;
    cout << "Направление: " << directionToString(testRecord.direction) << endl;
    cout << "Скорость: " << testRecord.speed << " м/с" << endl << endl;
    
  
    cout << "Тест преобразования строки:" << endl;
    try {
        WindDirection dir = stringToDirection("West");
        cout << "Строка 'West' преобразована в: " 
             << directionToString(dir) << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
  
    cout << endl << "Проверка порога скорости (" 
         << HIGH_SPEED_THRESHOLD << " м/с):" << endl;
    if (testRecord.speed > HIGH_SPEED_THRESHOLD) {
        cout << "Скорость " << testRecord.speed 
             << " м/с превышает порог!" << endl;
    } else {
        cout << "Скорость " << testRecord.speed 
             << " м/с НЕ превышает порог." << endl;
    }
    
    return 0;
}