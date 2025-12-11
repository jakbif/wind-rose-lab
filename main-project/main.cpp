#include <iostream>
#include "wind_record.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "================================\n";
    cout << "Запись #" << (i + 1) << "\n";
    cout << "Дата:      " << setw(2) << records[i]->date.day << "." 
     << setw(2) << records[i]->date.month << "." 
     << records[i]->date.year << "\n";
    cout << "Направление: " << directionToString(records[i]->direction) << "\n";
    cout << "Скорость:    " << fixed << setprecision(1) 
     << records[i]->speed << " м/с\n";
    cout << "================================\n\n";
    
    WindRecord* records[MAX_RECORDS];
    int size;
    
    try {
        read("data.txt", records, size);
        cout << "Прочитано записей: " << size << "\n\n";
        
        for (int i = 0; i < size; i++) {
            cout << "Запись " << (i + 1) << ":\n";
            cout << "  Дата: " << records[i]->date.day << "." 
                 << records[i]->date.month << "." 
                 << records[i]->date.year << "\n";
            cout << "  Направление: " << directionToString(records[i]->direction) << "\n";
            cout << "  Скорость: " << records[i]->speed << " м/с\n\n";
        }
        
        for (int i = 0; i < size; i++) {
            delete records[i];
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }
    
    return 0;
}