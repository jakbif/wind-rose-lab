#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

void read(const char* file_name, WindRecord* array[], int& size) {
    ifstream file(file_name);
    if (!file.is_open()) {
        throw "Ошибка открытия файла";
    }
    
    size = 0;
    int day, month, year = 2024;
    string directionStr;
    double speed;
    
    while (file >> day >> month >> directionStr >> speed) {
        if (size >= MAX_RECORDS) break;
        
        try {
            WindDirection direction = stringToDirection(directionStr);
            WindRecord* record = new WindRecord(day, month, year, direction, speed);
            array[size] = record;
            size++;
        }
        catch (const exception& e) {
            cout << "Ошибка в строке " << (size + 1) << ": " << e.what() << endl;
        }
    }
    
    file.close();
}