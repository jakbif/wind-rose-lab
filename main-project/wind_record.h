#ifndef WIND_RECORD_H
#define WIND_RECORD_H
#include "constants.h"
#include <string>

enum class WindDirection {
    North, Northeast, East, Southeast,
    South, Southwest, West, Northwest, COUNT
};

struct Date {
    int day;
    int month;
    int year;
};

struct WindRecord {
    Date date;
    WindDirection direction;
    double speed;
    
    WindRecord() : date{0,0,2024}, direction(WindDirection::North), speed(0.0) {}
    WindRecord(int d, int m, int y, WindDirection dir, double s) 
        : date{d,m,y}, direction(dir), speed(s) {}
};

WindDirection stringToDirection(const std::string& str);
std::string directionToString(WindDirection dir);
#endif