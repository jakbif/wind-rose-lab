#include "wind_record.h"
#include <map>
#include <stdexcept>
#include <string>

using namespace std;
WindDirection stringToDirection(const string& str) {
    static const map<string, WindDirection> directionMap = {
        {"North", WindDirection::North},
        {"Northeast", WindDirection::Northeast},
        {"East", WindDirection::East},
        {"Southeast", WindDirection::Southeast},
        {"South", WindDirection::South},
        {"Southwest", WindDirection::Southwest},
        {"West", WindDirection::West},      
        {"Northwest", WindDirection::Northwest}
    };
    
    auto it = directionMap.find(str);
    if (it != directionMap.end()) {
        return it->second;
    }
    throw runtime_error("Unknown wind direction: " + str);
}
string directionToString(WindDirection dir) {
    switch (dir) {
        case WindDirection::North: return "North";
        case WindDirection::Northeast: return "Northeast";
        case WindDirection::East: return "East";
        case WindDirection::Southeast: return "Southeast";
        case WindDirection::South: return "South";
        case WindDirection::Southwest: return "Southwest";
        case WindDirection::West: return "West";
        case WindDirection::Northwest: return "Northwest";
        default: return "Unknown";
    }
}