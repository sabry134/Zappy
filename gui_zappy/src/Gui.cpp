/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.cpp
*/

#include "Gui.hpp"


Gui::Gui(int ac, char **av) : _win(sf::VideoMode(1920, 1080), "Zappy") , _map(1920, 1080), _cmdHandler()
{
    
    if (ac == 2 && std::string(av[1]) == "-help")
        throw std::invalid_argument("Help");
    GetOpt getOpt(ac, av);
    _port = getOpt.getPort();
    _host = getOpt.getHost();
    _comm.setHost(_host);
    _comm.setPort(_port);
    this->_interfaceOn = false;
    this->_win.setFramerateLimit(60);
    std::cout << "Port: " << _port << std::endl;
    std::cout << "Host: " << _host << std::endl;
}

void Gui::initGui()
{
    try {
        this->_comm.connectToServer();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Gui::guiLoop()
{
    int updater = 0;
    while (this->_win.isOpen()) {
        this->updateGui(updater);
        this->_map.updateMap();
        this->_map.updateTexture();
        this->eventHandler();
        this->_win.clear(sf::Color::Black);
        this->_win.draw(this->_map);
        if (_interfaceOn == true)
           this->_win.draw(this->_interface);
        for (auto i = 0; i < this->_map.getIncantationList().size(); i++) {
            _win.draw(this->_map.getIncantationList().at(i));
        }
        for (auto i = 0; i < this->_map.getBroadcastList().size(); i) {
            this->_win.draw(this->_map.getBroadcastList().at(i));
        }
        this->_win.display();
        updater++;
    }
}

std::string Gui::getPort() const
{
    return _port;
}

std::string Gui::getHost() const
{
    return _host;
}

void Gui::updateGui(int updater)
{
    this->_comm.readFromServer();
    std::string cmd = "";
    while ((cmd = this->_comm.popCmd()) != "")
    {
        this->_cmdHandler.callFunction(cmd, this->_map);
    }
    if (updater % (this->_map.getSize().x * this->_map.getSize().y) == 0)
        this->_comm.writeToServer("mct\n");
    for (auto it = this->_map.getTeam().begin(); it != this->_map.getTeam().end(); it++) {
        for (auto player = (*it).getPlayerList().begin() ; player != (*it).getPlayerList().end(); player++) {
            this->_comm.writeToServer(std::string("ppo ").append(std::to_string((*player).getId())).append("\n"));
            this->_comm.writeToServer(std::string("pin ").append(std::to_string((*player).getId())).append("\n"));
            if (updater % 120 == 0) {
                this->_comm.writeToServer(std::string("plv ").append(std::to_string((*player).getId())).append("\n"));
            }
        }
    }
    int i = 0;
    while (i < this->_map.getIncantationList().size()) {
        this->_map.getIncantationList().at(i).addTime(5);
        i++;
    }
}

void Gui::eventHandler()
{
    sf::Event event{};
    sf::RenderStates s;
    while (this->_win.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            this->_win.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            this->_map.moveMap(10, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            this->_map.moveMap(-10, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            this->_map.moveMap(0, -10);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            this->_map.moveMap(0, 10);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
            this->_map.zoom(true);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
            this->_map.zoom(false);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            try {
                this->_tileClicked = this->_map.getTileInfo(sf::Mouse::getPosition(this->_win));
                this->_interfaceOn = true;
                this->_interface = Interface(this->_tileClicked);
            } catch (std::exception &e) {
                e.what();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            this->_interfaceOn = false;
        }
    }
}
