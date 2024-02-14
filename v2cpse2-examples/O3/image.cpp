#include "image.hpp"

Picture::Picture(sf::Vector2f pos, std::string path):
    Object(pos),
    path(path)
{}

void Picture::draw(sf::RenderWindow & window){
    image.loadFromFile(path);
    sprite.setTexture(image);
    sprite.setPosition(position);

    window.draw(sprite);
}

sf::FloatRect Picture::getBoundingBox(){
    sf::IntRect sprite_rect_int = sprite.getTextureRect();

    return sf::FloatRect(static_cast< float >( sprite_rect_int.left ),
                         static_cast< float >( sprite_rect_int.top ),
                         static_cast< float >( sprite_rect_int.width ),
                         static_cast< float >( sprite_rect_int.height ));
}

sf::Vector2f Picture::getPosition(){
    return sprite.getPosition();
}