#include "ToyRobot.h"
#include "Command.h"
#include "Table.h"

#include <iostream>

using namespace std;

int main() {
    // Create ToyRobot
    ToyRobot toyRobot;

    // Create table of 5x5 unit size
    Table table(5,5);

    // Create this object for parsing the input command
    Command command(toyRobot, table);

    // Starting enterint commands for the Toy Robot
    cout << "Enter robot command: " << endl;

    for(;;) {
        string inputCommand;
        getline(cin, inputCommand);
        //cout << "Command: " << inputCommand << endl;
        command.parseInputCommand (inputCommand);
    }
    return EXIT_SUCCESS;
}