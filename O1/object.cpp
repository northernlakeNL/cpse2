#include "Object.hpp"

void Object::move(sf::Vector2f delta){
    position+=delta;
}

sf::FloatRect Object::getBoundingBox() const {
    return sf::FloatRect(position, sf::Vector2f(0, 0));
}