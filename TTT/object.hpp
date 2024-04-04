#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object{
protected:
    sf::Vector2f position;
public:
    Object(sf::Vector2f position):
        position(position)
        {}

    virtual void draw(sf::RenderWindow &window);
};

#endif