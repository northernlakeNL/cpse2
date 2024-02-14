#include <SFML/Graphics.hpp>
#include "square.hpp"

square::square(sf::Vector2f pos, sf::Vector2f size, sf::Color color) :
    Object(pos),
    size(size),
    color(color)
{}

void square::draw( sf::RenderWindow & window) {
    
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(color);
    window.draw(rect);
}

void square::move(sf::Vector2f delta){
    position += delta;
}

sf::FloatRect square::getBoundingBox() const{ 
    return rect.getGlobalBounds();
}
