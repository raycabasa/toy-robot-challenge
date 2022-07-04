#include "ToyRobot.h"

#include <iostream>
#include <sstream>

using namespace std;

ToyRobot::ToyRobot()
    :_position(nullptr)
{

}

ToyRobot::~ToyRobot() {

}

// Executes PLACE command
void ToyRobot::place(const Position& position, Table& table) {
    Coordinate coordinate = position.getCoordinates();
    if (table.isOutOfBounds(coordinate)) {
        // Bail out if the coordinates are out of bounds with the size of our table
        // to prevent the robot from falling 
        return;
    }
    _position.reset(new Position(position));
}

// Executes MOVE command
void ToyRobot::move(Table& table) {
    if (!_position) {
        cout << "You need to place the robot correctly to the table first. Use 'PLACE' command." << endl;
        return;
    }
    int x = _position->getCoordinates().getXCoordinate();
    int y = _position->getCoordinates().getYCoordinate();
    Direction direction = _position->getDirection();

    /*
     * Increment or decrement our coordinates depending on where our robot is facing
     * 
     * NORTH - increment our Y coordinate because the robot goes up once it move
     * SOUTH - decrement our Y coordinate because the robot will move down
     * EAST  - increment our X coordinate because the robot will move further horizontally
     * WEST  - decrement out X coodrinate because the robot will move closer horizontally to the origin (0,0)
     */
    switch (direction) {
        case Direction::NORTH:
            y++;
            break;
        case Direction::SOUTH:
            y--;
            break;
        case Direction::EAST:
            x++;
            break;
        case Direction::WEST:
            x--;
            break;
        default:
            cout << "Hey, I'm confused where we are heading to!" << endl; 
            return;
    }

    Coordinate coordinate(x,y);
    if (table.isOutOfBounds(coordinate)) {
        cout << "Can't do that or else I will fall. :-(" << endl;
        return;
    }

    // Move our robot to the specified coordinates
    _position->setCoordinates(coordinate);
}

// Executes LEFT command
void ToyRobot::rotateLeft() {
    if (!_position) {
        cout << "You need to place the robot correctly to the table first. Use 'PLACE' command." << endl;
        return;
    }

    Direction direction = _position->getDirection();
    switch (direction) {
        case Direction::NORTH:
            direction = Direction::WEST;
            break;
        case Direction::SOUTH:
            direction = Direction::EAST;
            break;
        case Direction::EAST:
            direction = Direction::NORTH;
            break;
        case Direction::WEST:
            direction = Direction::SOUTH;
            break;
        default:
            cout << "Hey, I'm confused where we are heading to!" << endl; 
            return;
    }

    // Change the direction on where our robot is facing to the LEFT with respect to its
    // current direction.
    _position->setDirection(direction);
}

// Executes RIGHT command
void ToyRobot::rotateRight() {
    if (!_position) {
        cout << "You need to place the robot correctly to the table first. Use 'PLACE' command." << endl;
        return;
    }

    Direction direction = _position->getDirection();
    switch (direction) {
        case Direction::NORTH:
            direction = Direction::EAST;
            break;
        case Direction::SOUTH:
            direction = Direction::WEST;
            break;
        case Direction::EAST:
            direction = Direction::SOUTH;
            break;
        case Direction::WEST:
            direction = Direction::NORTH;
            break;
        default:
            cout << "Hey, I'm confused where we are heading to!" << endl; 
            return;
    }

    // Change the direction on where our robot is facing to the RIGHT with respect to its
    // current direction.
    _position->setDirection(direction);
}

// Executes REPORT command
string ToyRobot::report() {
    stringstream report;
    if (!_position) {
        report << "You need to place the robot correctly to the table first. Use 'PLACE' command.";
    } else {
        report << "Output: " << _position->getCoordinates().getXCoordinate() << "," << _position->getCoordinates().getYCoordinate() << "," << _position->getDirectionString();
    }
    cout << report.str() << endl;
    return report.str();
}




