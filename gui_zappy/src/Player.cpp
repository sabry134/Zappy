/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(int id, int x, int y, Orientation o, int level, std::string teamName)
{
    this->_id = id;
    this->pos.x = x;
    this->pos.y = y;
    this->_orientaton = o;
    this->level = level;
    this->_teamName = teamName;
    inventory.DERAUMERE = 0;
    inventory.FOOD = 0;
    inventory.LINEMATE = 0;
    inventory.MENDIANE = 0;
    inventory.PHIRAS = 0;
    inventory.SIBUR = 0;
    inventory.THYSTAME = 0;
}

Player::~Player()
{
}

Player::Player(const Player &p)
{
    this->_id = p.getId();
    this->pos = p.getPos();
    this->level = p.getLevel();
    this->_orientaton = p.getOrientation();
    this->_teamName = p.getTeamName();
    this->_incantation = p.getIncantation();
}

int Player::getLevel() const
{
    return this->level;
}

void Player::setLevel(int lv)
{
    this->level = lv;
}

int Player::getId() const
{
    return this->_id;
}

bool Player::getIncantation() const
{
    return this->_incantation;
}

void Player::setIncantation(bool a)
{
    this->_incantation = a;
}

sf::Vector2u Player::getPos() const
{
    return this->pos;
}

void Player::setPos(sf::Vector2u pos)
{
    this->pos = pos;
}

std::string Player::getTeamName() const
{
    return this->_teamName;
}

void Player::setTeamName(std::string name)
{
    this->_teamName = name;
}

Orientation Player::getOrientation() const
{
    return this->_orientaton;
}

void Player::setOrientation(Orientation o)
{
    this->_orientaton = o;   
}