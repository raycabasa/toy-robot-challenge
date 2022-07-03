#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "ToyRobot.h"
#include "Table.h"

#include <functional>
#include <map>
#include <regex>
#include <string>

typedef std::unordered_map<std::string, std::function<void(const std::smatch & matched)>> CommandMap;

class Command
{
    public:
        Command(ToyRobot& toyRobot, Table& table);
        ~Command();

        void parseInputCommand(std::string inputCommand);
        void registerValidCommands();
        CommandMap getCommands();

    private:
        ToyRobot & _toyRobot;
        Table & _table;
        CommandMap _commands;

};

#endif // __COMMAND_H__