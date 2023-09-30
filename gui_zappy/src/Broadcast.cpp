/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast
*/

#include "Broadcast.hpp"

Broadcast::Broadcast(sf::Vector2f pos, float radius, std::string text)
{
    this->_font = std::make_shared<sf::Font>(sf::Font());
    if (!(*this->_font).loadFromFile("gui_zappy/assets/arial.ttf"))
        throw std::exception();
    this->_text.setFillColor(sf::Color::Yellow);
    this->_text.setString("I AM BROADCASTING THIS SHIT");
    this->_text.setFont(*this->_font);
    this->_text.setCharacterSize(24);
    this->_text.setPosition(pos.x, pos.y - 10);
    _circle.setPosition(pos);
    _circle.setRadius(radius);
    _circle.setOutlineThickness(2);
    _circle.setFillColor(sf::Color::White);
    _circle.setOutlineColor(sf::Color::Blue);
    this->_nbScale = 0;
    this->scale = 1;
}

Broadcast::~Broadcast()
{
}

void Broadcast::scaleCircle()
{
    this->_circle.scale(1.05, 1.05);
    this->_text.scale(1.05, 1.05);
    this->_nbScale++;
}

float Broadcast::getScaleNb()
{
    return this->_nbScale;
}
