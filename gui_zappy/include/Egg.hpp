/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Egg
*/

#ifndef EGG_HPP_
#define EGG_HPP_
    #include <SFML/Graphics.hpp>
class Egg {
    public:
        Egg(int id, sf::Vector2u _pos);
        ~Egg();
        int getId();
        sf::Vector2u getPos();
    protected:
    private:
        int _id;
        sf::Vector2u _pos;
};



#endif /* !EGG_HPP_ */
