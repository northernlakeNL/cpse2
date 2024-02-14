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

    virtual sf::FloatRect getBoundingBox();

    virtual sf::Vector2f getPosition();

    void updatePosition(sf::Vector2f new_pos){
        position = new_pos;
    }


};

#endif
