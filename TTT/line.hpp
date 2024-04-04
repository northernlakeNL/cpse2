#ifndef _LINE_HPP_
#define _LINE_HPP_

#include <SFML/Graphics.hpp>
#include "object.hpp"

class Line: public Object{
private:
    sf::Vector2f size;
    sf::Color color;
public:
    sf::RectangleShape rect;

    Line(sf::Vector2f pos, sf::Vector2f size, sf::Color color);

    void draw(sf::RenderWindow & window) override;
};

#endif // _LINE_HPP_