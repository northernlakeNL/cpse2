#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"
#include <iostream>

class ball: public Object{
private:
    float size;
    int clr_choice = 0;
    sf::Color colors[3] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue};
public:
    sf::CircleShape circle;
    ball(sf::Vector2f pos, float size = 20.0);

    void draw(sf::RenderWindow & window) override;

    void move( sf::Vector2f delta) override;

    sf::Vector2f collision(std::vector<Object*> rectangles, sf::Vector2f speed);

    void paddleHit(std::vector<Object*> rectangles);

    sf::FloatRect getBoundingBox() const override;

};

#endif