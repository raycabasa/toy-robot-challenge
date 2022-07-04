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
    // Transform the command to uppercase because we're letting lowercase in the
    // input command and we need to convert it to uppercase for the map key value.
    transform(command.begin(), command.end(),command.begin(), ::toupper);
    for(auto it = directions.begin(); it != directions.end(); it++) {
        if (command.compare(it->first) == 0) {
            return it->second;
        }
    }
    // In case we don't find any, just make NORTH our default directory.
    // In honor of the House of Stark.
    return Direction::NORTH;
}

string getDirectionToString(Direction direction) {
    for(auto it = directions.begin(); it != directions.end(); it++) {
        if (it->second == direction) {
            return it->first;
        }
    }
    return "NORTH";
}
