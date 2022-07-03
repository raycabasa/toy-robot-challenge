#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include <string>

enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

Direction parseDirectionCommand(std::string command);
std::string getDirectionToString(Direction direction);

#endif // __DIRECTION_H__