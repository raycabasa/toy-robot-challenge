#include "Coordinate.h"

#include <iostream>
#include <sstream>

using namespace std;

Coordinate::Coordinate()
    : _x(0), _y(0)
{

}

Coordinate::Coordinate(int x, int y) {
    _x = x;
    _y = y;
}

Coordinate::~Coordinate() {

}

void Coordinate::setXCoordinate(int x) {
    _x = x;
}

int Coordinate::getXCoordinate() const {
    return _x;
}

void Coordinate::setYCoordinate(int y) {
    _y = y;
}

int Coordinate::getYCoordinate() const {
    return _y;
}

string Coordinate::toString() const {
    stringstream coordinates;
    coordinates << _x << "," << _y;
    return coordinates.str();
}
