#ifndef __POSITION_H__
#define __POSITION_H__

#include "Coordinate.h"
#include "Direction.h"

#include <string>

class Position
{
    public:
        Position(const Coordinate& coordinate, const Direction& direction);
        ~Position();

        void setCoordinates(const Coordinate& coordinate);
        void setDirection(const Direction& direction);

        const Coordinate getCoordinates() const;
        const Direction getDirection() const;

        std::string getDirectionString() const;

    private:
        Coordinate _coordinate;
        Direction _direction;
        
};

#endif // __POSITION_H__