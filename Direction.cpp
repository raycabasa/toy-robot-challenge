#include "Direction.h"

#include <algorithm>
#include <iostream>
#include <map>


using namespace std;

static map<const char *, Direction> directions = {
    {"NORTH", Direction::NORTH},
    {"SOUTH", Direction::SOUTH},
    {"EAST", Direction::EAST},
    {"WEST", Direction::WEST},
};

Direction parseDirectionCommand(string command) {
    transform(command.begin(), command.end(),command.begin(), ::toupper);
    for(auto it = directions.begin(); it != directions.end(); it++) {
        if (command.compare(it->first) == 0) {
            //cout << "Direction: FOUND A MATCH! Command = " << command << endl;
            //cout << "Direction: " << it->first << endl;
            return it->second;
        }
    }
    return Direction::NORTH;
}

string getDirectionToString(Direction direction) {
    for(auto it = directions.begin(); it != directions.end(); it++) {
        if (it->second == direction) {
            //cout << "Direction: FOUND A MATCH!" << endl;
            //cout << "Direction: " << it->first << endl;
            return it->first;
        }
    }
    return "NORTH";
}
