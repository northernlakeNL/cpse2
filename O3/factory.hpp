#include <SFML/Graphics.hpp>
#include <sstream>
#include "ball.hpp"
#include "square.hpp"
#include "image.hpp"
#include "Object.hpp"
#include <iostream>

class Factory{
public:
    Factory() = default;
    sf::Color getColor(std::string);
    Object* makeShape(std::string line);
    std::string makeUpper(std::string link);
};