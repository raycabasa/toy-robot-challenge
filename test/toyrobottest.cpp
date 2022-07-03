/* Unit testing for Toy Robot Challenge */
#include <assert.h>
#include <iostream>

#include "Command.h"
#include "Coordinate.h"
#include "Direction.h"
#include "Position.h"
#include "Table.h"
#include "ToyRobot.h"

using namespace std;

static void testCommand() {
    ToyRobot toyRobot;
    Table table(5,5);
    Command command(toyRobot, table);

    cout << endl << "Start unit testing for commands..." << endl;

    // valid PLACE upper case commands
    assert(command.parseInputCommand("PLACE 0,0,NORTH"));
    assert(command.parseInputCommand("PLACE 0,0,SOUTH"));
    assert(command.parseInputCommand("PLACE 0,0,EAST"));
    assert(command.parseInputCommand("PLACE 0,0,WEST"));

    // valid PLACE lower case commands
    assert(command.parseInputCommand("place 0,0,north"));
    assert(command.parseInputCommand("place 0,0,south"));
    assert(command.parseInputCommand("place 0,0,east"));
    assert(command.parseInputCommand("place 0,0,west"));

    // combination of upper and lowercase
    assert(command.parseInputCommand("PLACE 0,0,north"));
    assert(command.parseInputCommand("Place 0,0,South"));
    assert(command.parseInputCommand("pLace 0,0,eaST"));
    assert(command.parseInputCommand("plACE 0,0,wEst"));

    // test the spacing of the command
    assert(command.parseInputCommand(" place 0,0,north "));
    assert(command.parseInputCommand("            place 0,0,north"));
    assert(command.parseInputCommand("place 0,0,north            "));
    assert(!command.parseInputCommand("place    0,0,north"));
    assert(!command.parseInputCommand("place 0,   0,north"));
    assert(!command.parseInputCommand("place 0,0,    north"));

    // MOVE command
    assert(command.parseInputCommand("move"));
    assert(command.parseInputCommand(" move "));
    assert(command.parseInputCommand("   move"));
    assert(command.parseInputCommand("MOVE"));

    // LEFT command
    assert(command.parseInputCommand("left"));
    assert(command.parseInputCommand(" left "));
    assert(command.parseInputCommand("   left"));
    assert(command.parseInputCommand("left   "));
    assert(command.parseInputCommand("LEFT"));
    assert(command.parseInputCommand("Left"));
    assert(command.parseInputCommand("lefT"));
    assert(!command.parseInputCommand("lef T"));

    // RIGHT command
    assert(command.parseInputCommand("right"));
    assert(command.parseInputCommand(" right "));
    assert(command.parseInputCommand("   right"));
    assert(command.parseInputCommand("right   "));
    assert(command.parseInputCommand("RIGHT"));
    assert(command.parseInputCommand("Right"));
    assert(command.parseInputCommand("righT"));
    assert(!command.parseInputCommand("r ight"));

    // RIGHT command
    assert(command.parseInputCommand("report"));
    assert(command.parseInputCommand(" report "));
    assert(command.parseInputCommand("   report"));
    assert(command.parseInputCommand("report   "));
    assert(command.parseInputCommand("REPORT"));
    assert(command.parseInputCommand("Report"));
    assert(command.parseInputCommand("reporT"));
    assert(!command.parseInputCommand("r eport"));
    
    cout << "Done testing commands... Success!" << endl << endl;
}

static void testCoordinate() {
    cout << "Start unit testing for coordinates..." << endl;

    // Compare if the coordinates have the same string value
    assert(Coordinate(0,0).toString() == "0,0");
    assert(Coordinate(-1,-5).toString() == "-1,-5");
    assert(Coordinate(40000,5000).toString() == "40000,5000");
    assert(Coordinate(-7,11).toString() == "-7,11");
    assert(!(Coordinate(0,0).toString() == "-7,11"));

    cout << "Done testing coordinates... Success!" << endl << endl;
}

static void testDirection() {
    cout << "Start unit testing for directions..." << endl;

    // test for the equivalent enum value
    assert (parseDirectionCommand("NORTH") == Direction::NORTH);
    assert (parseDirectionCommand("SOUTH") == Direction::SOUTH);
    assert (parseDirectionCommand("EAST") == Direction::EAST);
    assert (parseDirectionCommand("WEST") == Direction::WEST);

    assert (!(parseDirectionCommand("NORTH") == Direction::SOUTH));
    assert (!(parseDirectionCommand("SOUTH") == Direction::EAST));
    assert (!(parseDirectionCommand("EAST") == Direction::WEST));
    assert (!(parseDirectionCommand("WEST") == Direction::NORTH));

    // test for the equivalent string value
    assert(getDirectionToString(Direction::NORTH) == "NORTH");
    assert(getDirectionToString(Direction::SOUTH) == "SOUTH");
    assert(getDirectionToString(Direction::EAST) == "EAST");
    assert(getDirectionToString(Direction::WEST) == "WEST");

    assert(!(getDirectionToString(Direction::NORTH) == "SOUTH"));
    assert(!(getDirectionToString(Direction::SOUTH) == "EAST"));
    assert(!(getDirectionToString(Direction::EAST) == "WEST"));
    assert(!(getDirectionToString(Direction::WEST) == "NORTH"));

    cout << "Done testing directions... Success!" << endl << endl;
}

static void testPosition() {
    cout << "Start unit testing for positions..." << endl;

    Position position = Position(Coordinate(0,0), Direction::NORTH);
    assert(position.getDirectionString() == "NORTH");
    assert(position.getCoordinates().getXCoordinate() == 0);
    assert(position.getCoordinates().getYCoordinate() == 0);
    
    position.setCoordinates(Coordinate(4,1));
    assert(position.getCoordinates().getXCoordinate() == 4);
    assert(position.getCoordinates().getYCoordinate() == 1);

    position.setCoordinates(Coordinate(5,6));
    assert(!(position.getCoordinates().getXCoordinate() == 6));
    assert(!(position.getCoordinates().getYCoordinate() == 7));

    position.setDirection(Direction::EAST);
    assert(position.getDirectionString() == "EAST");
    position.setDirection(Direction::WEST);
    assert(!(position.getDirectionString() == "EAST"));

    cout << "Done testing positions... Success!" << endl << endl;
}

static void testTable() {
    cout << "Start unit testing for table..." << endl;
    
    Table table(5,5);
    assert(table.getLength() == 5);
    assert(table.getWidth() == 5);

    Coordinate coordinate(6,6);
    assert(table.isOutOfBounds(coordinate));

    Table table1(20,50);
    assert(table1.getLength() == 20);
    assert(table1.getWidth() == 50);

    Coordinate coordinate1(10,15);
    assert(!table1.isOutOfBounds(coordinate1));


    cout << "Done testing table... Success!" << endl << endl;
}

static void testToyRobot() {
    cout << "Start unit testing for table..." << endl;

    ToyRobot toyRobot;
    Table table(5,5);

    // execute command before a valid PLACE
    toyRobot.move(table);
    toyRobot.rotateLeft();
    toyRobot.rotateRight();
    assert(toyRobot.report() == "You need to place the robot to the table. Use 'PLACE' command.");

    // test PLACE command
    Position position1(Coordinate(0,0), Direction::NORTH);
    toyRobot.place(position1, table);
    assert(toyRobot.report() == "Output: 0,0,NORTH");

    // test MOVE command
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 0,1,NORTH");
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 0,2,NORTH");

    // test RIGHT command
    toyRobot.rotateRight();
    assert(toyRobot.report() == "Output: 0,2,EAST");
    toyRobot.move(table);
    toyRobot.move(table);
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 3,2,EAST");

    // test LEFT command
    toyRobot.rotateLeft();
    assert(toyRobot.report() == "Output: 3,2,NORTH");
    toyRobot.move(table);
    toyRobot.move(table);
    toyRobot.move(table);

    // test out of bounds move
    // This is way beyond the edge of the table, robot should not fall.
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 3,5,NORTH");
    toyRobot.rotateRight();
    toyRobot.move(table);
    toyRobot.move(table);
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 5,5,EAST");

    // Place back to origin (0,0) but facing WEST
    Position position2(Coordinate(0,0), Direction::WEST);
    toyRobot.place(position2, table);
    assert(toyRobot.report() == "Output: 0,0,WEST");

    // This move will make the robot fall to the West side but it should not.
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 0,0,WEST");

    // Another fall scenario
    toyRobot.rotateLeft();
    toyRobot.move(table);
    assert(toyRobot.report() == "Output: 0,0,SOUTH");

    cout << "Done testing Toy Robot... Success!" << endl;
}

int main(int /* argc */, char ** /* argv */) {
    cout << "Start Toy Robot Challenge unit testing." << endl;
    testCommand();
    testCoordinate();
    testDirection();
    testPosition();
    testTable();
    testToyRobot();
    cout << "Finish Toy Robot Challenge unit testing." << endl;
    return EXIT_SUCCESS;
}