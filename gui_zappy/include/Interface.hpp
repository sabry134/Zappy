/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Interface
*/

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include "Map.hpp"

class Interface : public sf::Drawable, public sf::Transformable {
    public:
        Interface() = default;
        Interface(struct Tile tile);
        ~Interface() = default;
        void displayInterface();

        void setTextFood(std::string text, sf::Vector2f pos, int size);
        void setTextlinemate(std::string text, sf::Vector2f pos, int size);
        void setTextDeraumere(std::string text, sf::Vector2f pos, int size);
        void setTextSibur(std::string text, sf::Vector2f pos, int size);
        void setTextMendiane(std::string text, sf::Vector2f pos, int size);
        void setTextPhiras(std::string text, sf::Vector2f pos, int size);
        void setTextThystame(std::string text, sf::Vector2f pos, int size);
        void setRect(sf::Vector2f pos, sf::Vector2f size);
        void print_tile();

        sf::RectangleShape _backRect;
        typedef struct text_s {
            sf::Text _textFood;
            sf::Text _textLinemate;
            sf::Text _textDeraumere;
            sf::Text _textSibur;
            sf::Text _textMendiane;
            sf::Text _textPhiras;
            sf::Text _textThystame;
        } text_t;
       
    protected:
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                states.transform *= getTransform();
                target.draw(_backRect, states);
                target.draw(_text._textFood, states);
                target.draw(_text._textLinemate, states);
                target.draw(_text._textDeraumere);
                target.draw(_text._textSibur);
                target.draw(_text._textMendiane);
                target.draw(_text._textPhiras);
                target.draw(_text._textThystame);
        }
        text_t _text;
        std::shared_ptr<sf::Font> _font;
        struct Tile _tile;
        std::string _fontTTf = "gui_zappy/assets/fonts/arial.ttf";
};

#endif /* !INTERFACE_HPP_ */
