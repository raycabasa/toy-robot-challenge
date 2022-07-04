#include "Command.h"
#include "Coordinate.h"
#include "Direction.h"
#include "Position.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Command::Command(ToyRobot& toyRobot, Table& table)
    : _toyRobot(toyRobot), _table(table)
{
    registerValidCommands();
}

Command::~Command() {

}

bool Command::parseInputCommand (string inputCommand) {
    /*
     * Go through the list of valid commands and check if the input string
     * command is one of them. If found, execute the corresponding lambda function
     * for executing the robot commands
     */
    CommandMap commands = getCommands();
    for (auto it = commands.begin(); it != commands.end(); it++) {
        regex rgx(it->first, std::regex_constants::icase);
        smatch matched;
        if (it->second && regex_match(inputCommand, matched, rgx)) {
            it->second(matched);
            return true;
        }
    }
    return false;
}

void Command::registerValidCommands() {
    /*
     * Register/add all the valid commands necessary for our robot's movement
     */

    // PLACE command
    _commands.insert(make_pair(
                            "^\\s*(PLACE)\\s([0-9]+),([0-9]+),(NORTH|SOUTH|EAST|WEST)\\s*$", 
                            [&] (const std::smatch & matched) {
                                /*
                                 * matched[] string token contains:
                                 *      matched[0] = whole command string
                                 *      matched[1] = PLACE command
                                 *      matched[2] = x coordinate
                                 *      matched[3] = y coordinate
                                 *      matched[4] = direction
                                 */

                                // 1. Set coordinate
                                int x = stoi(matched[2]);
                                int y = stoi(matched[3]);
                                Coordinate coordinate(x, y);

                                // 2. Get direction the robot will face
                                Direction direction = parseDirectionCommand(matched[4]);

                                // 3. Set coordinate and direction
                                Position position(coordinate, direction);

                                // 4. Execute command
                                _toyRobot.place(position, _table);
                            }
    ));

    // MOVE command
    _commands.insert(make_pair(
                            "^\\s*(MOVE)\\s*$", 
                            [&] (const std::smatch & matched) {
                                _toyRobot.move(_table);
                            }
    ));

    // LEFT command
    _commands.insert(make_pair(
                            "^\\s*(LEFT)\\s*$", 
                            [&] (const std::smatch & matched) {
                                _toyRobot.rotateLeft();
                            }
    ));

    // RIGHT command
    _commands.insert(make_pair(
                            "^\\s*(RIGHT)\\s*$", 
                            [&] (const std::smatch & matched) {
                                _toyRobot.rotateRight();
                            }
    ));

    // REPORT command
    _commands.insert(make_pair(
                            "^\\s*(REPORT)\\s*$", 
                            [&] (const std::smatch & matched) {
                                _toyRobot.report();
                            }
    ));

    // End of map
}

// Returns the list of available commands for our Toy Robot
CommandMap Command::getCommands() {
    return _commands;
}


