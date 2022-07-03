#include "Coordinate.h"

#include <iostream>
#include <sstream>

using namespace std;

Coordinate::Coordinate() {

}

Coordinate::Coordinate(int x, int y) {
    _x = x;
    _y = y;
    //cout << ">>>>>>> Coordinate CONSTRUCTOR: x = " << _x << ", y = " << _y << endl;
}

Coordinate::~Coordinate() {

}

void Coordinate::setXCoordinate(int x) {
    _x = x;
    //cout << "Coordinate class: setXCoordinate: _x = " << _x << endl;
}

int Coordinate::getXCoordinate() const {
    //cout << "Coordinate class: getXCoordinate: _x = " << _x << endl;
    return _x;
}

void Coordinate::setYCoordinate(int y) {
    _y = y;
    //cout << "Coordinate class: setXCoordinate: _y = " << _y << endl;
}


int Coordinate::getYCoordinate() const {
    //cout << "Coordinate class: getYCoordinate: _y = " << _y << endl;
    return _y;
}

string Coordinate::toString() {
    stringstream coordinates;
    coordinates << _x << "," << _y;
    return coordinates.str();
}
