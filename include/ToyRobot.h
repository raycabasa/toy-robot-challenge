#ifndef __TOY_ROBOT__
#define __TOY_ROBOT__

#include "Position.h"
#include "Table.h"

#include <memory>
#include <string>

class ToyRobot
{
    public:
        ToyRobot();
        ~ToyRobot();

        void place(const Position& position, Table& table);
        void move(Table& table);
        void rotateLeft();
        void rotateRight();
        std::string report();

    private:
        std::unique_ptr<Position> _position;

};

#endif // __TOY_ROBOT__