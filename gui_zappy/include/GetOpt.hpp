/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GetOpt.h
*/

#ifndef ZAPPY_GETOPT_H
    #define ZAPPY_GETOPT_H
    #include <string>
    #include <iostream>
    #include <exception>
class GetOpt {
public:
    GetOpt(int ac, char **av);
    ~GetOpt() = default;

    std::string getPort() const;
    std::string getHost() const;

private:
    std::string _port;
    std::string _host;
};

#endif //ZAPPY_GETOPT_H
