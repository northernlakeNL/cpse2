#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f pos, float size) : 
    Object(pos),
    size(size)
    {
    }


void ball::draw( sf::RenderWindow & window ) {
    circle.setRadius(size);
    circle.setPosition( position );
    window.draw(circle);
}

void ball::move( sf::Vector2f delta) {
    position+= delta;
}

sf::Vector2f ball::collision(std::vector<Object*> rectangles, sf::Vector2f speed){
    sf::Vector2f oldPosition = circle.getPosition();
    for (auto& rect : rectangles){
        if (circle.getGlobalBounds().intersects(rect->getBoundingBox())){
            sf::FloatRect ballBounds = circle.getGlobalBounds();
            sf::FloatRect rectBounds = rect->getBoundingBox();
            if (ballBounds.left < rectBounds.left && speed.x >0){
                speed.x = -speed.x;
            }
            else if (ballBounds.left +ballBounds.width > rectBounds.left + rectBounds.width && speed.x < 0){
                speed.x = -speed.x;
            }

            if (ballBounds.top < rectBounds.top && speed.y > 0){
                speed.y = -speed.y;
            }
            else if (ballBounds.top +ballBounds.height > rectBounds.top + rectBounds.height && speed.y < 0){
                speed.y = -speed.y;
            }
            while (circle.getGlobalBounds().intersects(rectBounds)){
                circle.move(speed);
                if (std::abs(circle.getPosition().x - oldPosition.x) >= 5 || 
                    std::abs(circle.getPosition().y - oldPosition.y) >= 5){
                    break;
                }
            }
            return collision(rectangles, speed);
        }
    }
    return speed;
}

bool ball::score(Object *rect){
    if (circle.getGlobalBounds().intersects(rect->getBoundingBox())){
        return true;
    }
    return false;
}

sf::FloatRect ball::getBoundingBox() const{ 
    return circle.getGlobalBounds();
}