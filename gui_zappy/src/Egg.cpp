/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Egg
*/

#include "Egg.hpp"

Egg::Egg(int id, sf::Vector2u pos)
{
    this->_id = id;
    this->_pos = pos;
}

Egg::~Egg()
{
}

int Egg::getId()
{
    return this->_id;
}

sf::Vector2u Egg::getPos()
{
    return this->_pos;
}
