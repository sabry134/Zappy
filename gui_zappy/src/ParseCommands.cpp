/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** ParseCommands.cpp
*/

#include "ParseCommands.hpp"

void ParseServerCommands::parseCommand(std::string command)
{
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;

    _command = command.substr(0, command.find(' '));
    command.erase(0, command.find(' ') + delimiter.length());
    while ((pos = command.find(delimiter)) != std::string::npos) {
        token = command.substr(0, pos);
        _arguments.push_back(token);
        command.erase(0, pos + delimiter.length());
    }
    _arguments.push_back(command);
}

std::string ParseServerCommands::getCommand() const
{
    return _command;
}

void ParseServerCommands::setCommand(const std::string &command)
{
    _command = command;
}

std::list<std::string> ParseServerCommands::getArguments() const
{
    return _arguments;
}

void ParseServerCommands::setArguments(const std::list<std::string> &arguments)
{
    _arguments = arguments;
}
