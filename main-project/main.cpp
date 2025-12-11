#include <iostream>
#include "wind_record.h"
#include "file_reader.h"
#include "constants.h"
#include "filter_functions.h"
using namespace std;
// Функция для выбора критерия фильтрации
bool (*selectFilterFunction()) (WindRecord*) {
    cout << "\nВыберите критерий фильтрации:\n";
    cout << "1. Западный ветер\n";
    cout << "2. Скорость ветра > 5 м/с\n";
    cout << "Ваш выбор: ";
    
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1:
            return checkWestWind;
        case 2:
            return checkHighSpeed;
        default:
            cout << "Неверный выбор, используем фильтр по умолчанию (западный ветер)\n";
            return checkWestWind;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №6. Роза ветров\n";
    cout << "Автор: [Ваше Имя]\n";
    cout << "Группа: [Ваша группа]\n\n";
    
    WindRecord* records[MAX_RECORDS];
    int size;
    
    try {
        read("data.txt", records, size);
        cout << "Прочитано записей: " << size << "\n\n";
        
        // Меню программы
        int choice;
        do {
            cout << "\n=== МЕНЮ ПРОГРАММЫ ===\n";
            cout << "1. Показать все записи\n";
            cout << "2. Фильтровать записи\n";
            cout << "0. Выход\n";
            cout << "Выберите действие: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    // Вывод всех записей
                    cout << "\n=== ВСЕ ЗАПИСИ ===\n";
                    for (int i = 0; i < size; i++) {
                        cout << "Запись " << (i + 1) << ":\n";
                        cout << "  Дата: " << records[i]->date.day << "." 
                             << records[i]->date.month << "." 
                             << records[i]->date.year << "\n";
                        cout << "  Направление: " << directionToString(records[i]->direction) << "\n";
                        cout << "  Скорость: " << records[i]->speed << " м/с\n\n";
                    }
                    break;
                    
                case 2:
                    // Фильтрация записей
                    {
                        bool (*filterFunc)(WindRecord*) = selectFilterFunction();
                        int filteredSize;
                        
                        WindRecord** filtered = filterRecords(records, size, filterFunc, filteredSize);
                        
                        cout << "\n=== ОТФИЛЬТРОВАННЫЕ ЗАПИСИ ===\n";
                        cout << "Найдено записей: " << filteredSize << "\n\n";
                        
                        for (int i = 0; i < filteredSize; i++) {
                            cout << "Запись " << (i + 1) << ":\n";
                            cout << "  Дата: " << filtered[i]->date.day << "." 
                                 << filtered[i]->date.month << "." 
                                 << filtered[i]->date.year << "\n";
                            cout << "  Направление: " << directionToString(filtered[i]->direction) << "\n";
                            cout << "  Скорость: " << filtered[i]->speed << " м/с\n\n";
                        }
                        
                        delete[] filtered;
                    }
                    break;
                    
                case 0:
                    cout << "Выход из программы...\n";
                    break;
                    
                default:
                    cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } while (choice != 0);
        
        // Освобождение памяти
        for (int i = 0; i < size; i++) {
            delete records[i];
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }
    
    return 0;
}