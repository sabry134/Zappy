/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Incantation
*/

#include "Incantation.hpp"

Incantation::Incantation(int level, sf::Vector2i pos, Player starter, std::list<Player> &participent) : _starter(starter)
{
    this->_level = level;
    this->_pos = pos;
    this->_participent = participent;
    this->_time = 0;
    this->_text = std::make_shared<sf::Texture>(sf::Texture());
    if (!(this->_text)->loadFromFile("gui_zappy/assets/GrassText.png", sf::IntRect(256, 0, 32, 32)))
    {
        throw std::exception();
    }
    this->_sprite.setTexture((*this->_text), true);
    this->_sprite.setOrigin(16, 16);
}

Incantation::~Incantation()
{
}

void Incantation::finishIncantation(int result)
{
    return;
}

sf::Vector2i& Incantation::getPos(void)
{
    return this->_pos;
}

Player& Incantation::getStarter(void)
{
    return this->_starter;
}

std::list<Player>& Incantation::getParticipent(void)
{
    return this->_participent;
}

void Incantation::addTime(int time)
{
    this->_time += time;
    this->_sprite.setRotation(_time % 360);
}

const sf::Sprite & Incantation::getSprite() const
{
    return this->_sprite;
}

void Incantation::setSpirtePos(sf::Vector2i pos)
{
    this->_sprite.setPosition(pos.x, pos.y);
}