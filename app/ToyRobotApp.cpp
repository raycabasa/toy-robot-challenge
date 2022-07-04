#include "ToyRobot.h"
#include "Command.h"
#include "Table.h"

#include <iostream>

using namespace std;

int main(int /* argc */, char ** /* argv */) {
    // Create ToyRobot
    ToyRobot toyRobot;

    // Create table of 5x5 unit size
    Table table(5,5);

    // Create this object for parsing the input command
    Command command(toyRobot, table);

    // Start entering commands for the Toy Robot
    cout << "Enter robot commands: " << endl;

    for(;;) {
        string inputCommand;
        // Wait for input commands from the command line
        getline(cin, inputCommand);
        command.parseInputCommand (inputCommand);
    }

    return EXIT_SUCCESS;
}