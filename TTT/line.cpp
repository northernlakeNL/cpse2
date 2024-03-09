#include <SFML/Graphics.hpp>
#include "line.hpp"

Line::Line(sf::Vector2f pos, sf::Vector2f size, sf::Color color) :
    Object(pos),
    size(size),
    color(color)
{}

void Line::draw( sf::RenderWindow & window) {
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(color);
    window.draw(rect);
}