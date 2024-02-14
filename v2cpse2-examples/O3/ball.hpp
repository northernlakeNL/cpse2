#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"

class ball: public Object{
private:
    float size;
    sf::Color color;
public:
    sf::CircleShape circle;
    ball(sf::Vector2f pos, float size, sf::Color color);

    void draw(sf::RenderWindow & window) override;

    sf::FloatRect getBoundingBox() override;

    sf::Vector2f getPosition() override;
};

#endif