#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"

class ball: public Object{
private:
    float size;
public:
    sf::CircleShape circle;
    ball(sf::Vector2f pos, float size = 20.0);

    void draw(sf::RenderWindow & window) override;

    void move( sf::Vector2f delta) override;

    sf::Vector2f collision(std::vector<Object*> rectangles, sf::Vector2f speed);

    bool score(Object *rect);

    sf::FloatRect getBoundingBox() const override;

};

#endif