/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Team
*/

#ifndef TEAM_HPP_
#define TEAM_HPP_
    #include <string>
    #include <vector>
    #include "Player.hpp"
    #include <random>
class Team {
    public:
        Team(std::string name);
        ~Team();
        std::vector<Player> &getPlayerList();
        std::string gatName();
        void addPlayer(Player player);
        int getNbPlayer();
        sf::Color getTeamColor();
    protected:
    private:
        int _nbPlayer;
        std::string _name;
        std::vector<Player> _playerList;
        sf::Color _teamColor;
};




#endif /* !TEAM_HPP_ */
