#include <SFML/Graphics.hpp>
#include <string>
#include "object.hpp"


class Picture: public Object{
private:
    std::string path;
public:
    sf::Texture image;
    sf::Sprite sprite;

    Picture(sf::Vector2f pos, std::string path);

    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBoundingBox() override;

    sf::Vector2f getPosition() override;
};