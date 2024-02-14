#include <SFML/Graphics.hpp>
#include "square.hpp"

square::square(sf::Vector2f pos, sf::Vector2f size, sf::Color color) :
    Object(pos),
    size(size),
    color(color),
    rect(size)
{}

void square::draw( sf::RenderWindow & window) {
    rect.setPosition(position);
    rect.setFillColor(color);
    window.draw(rect);
}

sf::FloatRect square::getBoundingBox(){
    return rect.getGlobalBounds();
}

sf::Vector2f square::getPosition(){
    return rect.getPosition();
}