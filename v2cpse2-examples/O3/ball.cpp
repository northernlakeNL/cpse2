#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f pos, float size, sf::Color color) : 
    Object(pos),
    size(size),
    color(color)
    {
    }


void ball::draw( sf::RenderWindow & window ) {
    circle.setRadius(size);
    circle.setPosition( position );
    circle.setFillColor(color);
    window.draw(circle);
}

sf::FloatRect ball::getBoundingBox(){
    return circle.getGlobalBounds();
}

sf::Vector2f ball::getPosition(){
    return circle.getPosition();
}