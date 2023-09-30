/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GetOpt.cpp
*/

#include "GetOpt.hpp"

GetOpt::GetOpt(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (std::string(av[i]) == "-p") {
            if (i + 1 < ac)
                _port = av[i + 1];
            else
                throw std::invalid_argument("Port missing");
        }
        if (std::string(av[i]) == "-h") {
            if (i + 1 < ac)
                _host = av[i + 1];
            else
                _host = "127.0.0.1";
        }
    }
    if (_host.empty())
        _host = "127.0.0.1";
    if (_port.empty())
        throw std::invalid_argument("Invalid argument");
}

std::string GetOpt::getPort() const
{
    return _port;
}

std::string GetOpt::getHost() const
{
    return _host;
}
