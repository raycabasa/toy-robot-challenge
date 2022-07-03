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
    // Search if valid command
    //cout << "PARSING COMMANDS..." << endl;
    CommandMap commands = getCommands();
    //cout << "commands size: " << commands.size() << endl;

    for (auto it = commands.begin(); it != commands.end(); it++) {
        regex rgx(it->first, std::regex_constants::icase);
        smatch matched;
        if (it->second && regex_match(inputCommand, matched, rgx)) {
            //cout << "Found a command: " << it->first << endl;
            it->second(matched);
            return true;
        }
    }
    //cout << "DID NOT FOUND: " << inputCommand << endl;
    return false;
}

void Command::registerValidCommands() {
    //cout << "Registering valid commands..." << endl;
    // PLACE
    _commands.insert(make_pair(
                            "^\\s*(PLACE)\\s([0-9]+),([0-9]+),(NORTH|SOUTH|EAST|WEST)\\s*$", 
                            [&] (const std::smatch & matched) {
                                //cout << ">>>>>>>>>>>>>>>>>>>>>>>>> PLACE Command" << endl;
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

                                // 3. Set position and direction
                                Position position(coordinate, direction);

                                // 4. Execute command
                                _toyRobot.place(position, _table);
                            }
    ));

    // MOVE
    _commands.insert(make_pair(
                            "^\\s*(MOVE)\\s*$", 
                            [&] (const std::smatch & matched) {
                                //cout << ">>>>>>>>>>>>>>>>>>>>>>>>> MOVE Command" << endl;
                                _toyRobot.move(_table);
                            }
    ));
    // LEFT
    _commands.insert(make_pair(
                            "^\\s*(LEFT)\\s*$", 
                            [&] (const std::smatch & matched) {
                                //cout << ">>>>>>>>>>>>>>>>>>>>>>>>> LEFT Command" << endl;
                                _toyRobot.rotateLeft();
                            }
    ));

    // RIGHT
    _commands.insert(make_pair(
                            "^\\s*(RIGHT)\\s*$", 
                            [&] (const std::smatch & matched) {
                                //cout << ">>>>>>>>>>>>>>>>>>>>>>>>> RIGHT Command" << endl;
                                _toyRobot.rotateRight();
                            }
    ));

    // REPORT
    _commands.insert(make_pair(
                            "^\\s*(REPORT)\\s*$", 
                            [&] (const std::smatch & matched) {
                                //cout << ">>>>>>>>>>>>>>>>>>>>>>>>> REPORT Command" << endl;
                                _toyRobot.report();
                            }
    ));

    // End of map
}

CommandMap Command::getCommands() {
    return _commands;
}


