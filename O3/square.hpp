#ifndef _SQUARE_HPP
#define _SQUARE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.hpp"

/**
 * \class square
 * \brief De klasse `square` is verantwoordelijk voor het maken van een vierkant object.
 * 
 * De klasse `square` is een subklasse van de klasse `Object`. De klasse heeft een vierkant object
 * met een bepaalde grootte en kleur. Het heeft een constructor die een positie, grootte en
 * kleur van het vierkant als invoer neemt. Ook heeft een functie om het vierkant te
 * tekenen op een venster, een functie om de omtrek van het vierkant te krijgen, een functie om de positie
 * van het vierkant te krijgen, en een functie om de positie van het vierkant bij te werken.
 * 
 * \note De positie is de positie van de linkerbovenhoek van het vierkant.
 * \note De grootte is de breedte en hoogte van het vierkant.
 * 
 * @see Object
 * @see sf::RectangleShape
 * @see square::square
 * @see square::draw
 * @see square::getBoundingBox
 * @see square::getPosition
 * @see square::updatePosition
*/

class Square : public Object {
private:
    sf::Vector2f size;
    sf::Color color;
public:
    sf::RectangleShape rect;
    Square(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBoundingBox() override;
    sf::Vector2f getPosition() override;
    void updatePosition(sf::Vector2f new_pos) override;
};

#endif