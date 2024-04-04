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
    virtual void move(sf::Vector2f delta);
    virtual sf::FloatRect getBoundingBox() const = 0;
    virtual void setColor(sf::Color clr){};
};

#endif
