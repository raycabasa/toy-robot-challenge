#include "Table.h"

Table::Table(int length, int width) {
    _length = length;
    _width = width;
}

Table::~Table() {
    
}

int Table::getLength() const {
    return _length;
}

int Table::getWidth() const {
    return _width;
}

bool Table::isOutOfBounds(const Coordinate & coordinate) {
    return (coordinate.getXCoordinate() < 0 ||
            coordinate.getYCoordinate() < 0 ||
            coordinate.getXCoordinate() > getLength() ||
            coordinate.getYCoordinate() > getWidth());
}