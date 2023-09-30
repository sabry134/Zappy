/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.hpp
*/

#ifndef B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
    #define B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP

    #include <exception>
    #include <Map.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <unistd.h>
    #include <memory>
    #include <list>

    #include "GetOpt.hpp"
    #include "ServerCommunication.hpp"
    #include "FunctionManager.hpp"
    #include "Interface.hpp"

class Gui {
    public:
        Gui() = default;
        Gui(int ac, char **av);
        ~Gui() = default;
        void initGui();
        void guiLoop();
        std::string getPort() const;
        std::string getHost() const;
        void updateGui(int updater);
    private:
        void eventHandler();
        std::string _port;
        std::string _host;
        ServerCommunication _comm;
        sf::RenderWindow _win;
        FunctionManager _cmdHandler;
        Map _map;
        struct Tile _tileClicked;
        Interface _interface;
        bool _interfaceOn;
};


#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
