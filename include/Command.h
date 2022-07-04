#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "ToyRobot.h"
#include "Table.h"

#include <functional>
#include <map>
#include <regex>
#include <string>

/* 
 * Need to typedef this so that we won't have to type this very long line whenever
 * we will use it.
 */
typedef std::unordered_map<std::string, std::function<void(const std::smatch & matched)>> CommandMap;

class Command
{
    public:
        Command(ToyRobot& toyRobot, Table& table);
        ~Command();

        bool parseInputCommand(std::string inputCommand);
        void registerValidCommands();
        CommandMap getCommands();

    private:
        ToyRobot & _toyRobot;
        Table & _table;
        CommandMap _commands;

};

#endif // __COMMAND_H__