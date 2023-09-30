/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** ParseCommands.hpp
*/

#ifndef B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_PARSECOMMANDS_HPP
    #define B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_PARSECOMMANDS_HPP

    #include <string>
    #include <list>
    #include <map>

class ParseServerCommands {
public:
    ParseServerCommands() = default;
    ~ParseServerCommands() = default;

    void parseCommand(std::string command);

    std::string getCommand() const;
    void setCommand(const std::string &command);

    std::list<std::string> getArguments() const;
    void setArguments(const std::list<std::string> &arguments);

private:
    std::string _command;
    std::list<std::string> _arguments;
};

#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_PARSECOMMANDS_HPP
