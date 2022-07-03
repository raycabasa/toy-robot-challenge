#include "Position.h"

#include <iostream>

using namespace std;


Position::Position(const Coordinate& coordinate, const Direction& direction)
    : _coordinate(coordinate), _direction(direction)
{
    //cout << "[Position] Initializing coordinates: x = " << _coordinate.getXCoordinate() << ", y = " << _coordinate.getYCoordinate() << endl;
}

Position::~Position() {

}

void Position::setCoordinates( const Coordinate& coordinate ) {
    _coordinate = coordinate;
}

void Position::setDirection( const Direction& direction) {
    _direction = direction;
}

const Coordinate Position::getCoordinates() const {
    return _coordinate;
}

const Direction Position::getDirection() const {
    return _direction;
}

string Position::getDirectionString() {
    return getDirectionToString(_direction);
}