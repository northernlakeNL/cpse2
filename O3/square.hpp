#ifndef _SQUARE_HPP
#define _SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <iostream>


class square :public Object {
private:
    sf::Vector2f size;
    sf::Color color;
public:
    sf::RectangleShape rect;
    
    square(sf::Vector2f pos, sf::Vector2f size, sf::Color color);

    void draw(sf::RenderWindow & window) override;

    sf::FloatRect getBoundingBox() override;

    sf::Vector2f getPosition() override;
};

#endif