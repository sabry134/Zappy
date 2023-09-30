/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Interface.cpp
*/

#include "Interface.hpp"

#include <utility>
 
Interface::Interface(struct Tile tile)
{
    _tile = std::move(tile);
    this->_font = std::make_shared<sf::Font>(sf::Font());
    (*_font).loadFromFile("gui_zappy/assets/arial.ttf");
    sf::Vector2f pos = {1700, 0};
    sf::Vector2f size = {500, 1080};
    setRect(pos, size);
    _text._textFood.setFont(*_font);
/*     _text._textFood.setString(std::to_string(_tile.FOOD));
    _text._textFood.setPosition(pos);
    _text._textFood.setCharacterSize(25);
    _text._textFood.setFillColor(sf::Color::Blue); */
    _text._textLinemate.setFont(*_font);
    _text._textDeraumere.setFont(*_font);
    _text._textMendiane.setFont(*_font);
    _text._textSibur.setFont(*_font);
    _text._textPhiras.setFont(*_font);
    _text._textThystame.setFont(*_font);
    print_tile();
}

void Interface::displayInterface()
{
    // display background
    // display text
}

void Interface::setTextFood(std::string text, sf::Vector2f pos, int size)
{
    _text._textFood.setString(text);
    _text._textFood.setPosition(pos);
    _text._textFood.setCharacterSize(size);
    _text._textFood.setFillColor(sf::Color::White);
}

void Interface::setTextlinemate(std::string text, sf::Vector2f pos, int size)
{
    _text._textLinemate.setString(text);
    _text._textLinemate.setPosition(pos);
    _text._textLinemate.setCharacterSize(size);
    _text._textLinemate.setFillColor(sf::Color::White);
}

void Interface::setTextDeraumere(std::string text, sf::Vector2f pos, int size)
{
    _text._textDeraumere.setString(text);
    _text._textDeraumere.setPosition(pos);
    _text._textDeraumere.setCharacterSize(size);
    _text._textDeraumere.setFillColor(sf::Color::White);
}

void Interface::setTextSibur(std::string text, sf::Vector2f pos, int size)
{
    _text._textSibur.setString(text);
    _text._textSibur.setPosition(pos);
    _text._textSibur.setCharacterSize(size);
    _text._textSibur.setFillColor(sf::Color::White);
}

void Interface::setTextMendiane(std::string text, sf::Vector2f pos, int size)
{
    _text._textMendiane.setString(text);
    _text._textMendiane.setPosition(pos);
    _text._textMendiane.setCharacterSize(size);
    _text._textMendiane.setFillColor(sf::Color::White);
}

void Interface::setTextPhiras(std::string text, sf::Vector2f pos, int size)
{
    _text._textPhiras.setString(text);
    _text._textPhiras.setPosition(pos);
    _text._textPhiras.setCharacterSize(size);
    _text._textPhiras.setFillColor(sf::Color::White);
}

void Interface::setTextThystame(std::string text, sf::Vector2f pos, int size)
{
    _text._textThystame.setString(text);
    _text._textThystame.setPosition(pos);
    _text._textThystame.setCharacterSize(size);
    _text._textThystame.setFillColor(sf::Color::White);
}

void Interface::setRect(sf::Vector2f pos, sf::Vector2f size)
{
    sf::Color gray(72, 72, 72);
    _backRect.setPosition(pos);
    _backRect.setSize(size);
    _backRect.setFillColor(gray);
}

void Interface::print_tile()
{
    sf::Vector2f vec = _backRect.getPosition();
    sf::Vector2f rect = _backRect.getSize();
    vec.y += 100;
    vec.x += 10;
    setTextFood(std::to_string(_tile.FOOD).append(" FOOD IS FOOD"), vec, 20);
    vec.y += 100;
    setTextlinemate(std::to_string(_tile.LINEMATE).append(" LINEMATE"), vec, 20);
    vec.y += 100;
    setTextDeraumere(std::to_string(_tile.DERAUMERE).append(" DERAUMERE"), vec, 20);
    vec.y += 100;
    setTextSibur(std::to_string(_tile.SIBUR).append(" SIBUR"), vec, 20);
    vec.y += 100;
    setTextMendiane(std::to_string(_tile.MENDIANE).append(" MENDIANE"), vec, 20);
    vec.y += 100;
    setTextPhiras(std::to_string(_tile.PHIRAS).append(" PHIRAS"), vec, 20);
    vec.y += 100;
    setTextThystame(std::to_string(_tile.THYSTAME).append(" THYSTAME"), vec, 20);
}