#ifndef _LINE_HPP_
#define _LINE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "object.hpp"

/**
 * \class Line
 * \brief De klasse `Line` is verantwoordelijk voor het maken van een lijn object.
 * 
 * De klasse `Line` is een subklasse van de klasse `Object`. De klasse `Line` heeft een lijn object
 * met een begin- en eindpunt en een bepaalde kleur. Het heeft een constructor die een
 * positie, eindpunt en kleur van de lijn als invoer neemt. Ook heeft het een functie om
 * de lijn te tekenen op een venster, een functie om de omtrek van de lijn te krijgen, een functie om
 * de positie van de lijn te krijgen, en een functie om de positie van de lijn bij te werken.
 * 
 * \note De positie is de positie van de linkerbovenhoek van de lijn.
 * 
 * @see Line::Line
 * @see Line::draw
 * @see Line::getBoundingBox
 * @see Line::getPosition
 * @see Line::updatePosition
 * @see Object
*/
class Line : public Object {
   private:
    sf::Vector2f end;
    sf::Color color;
    sf::VertexArray lines;
   public:
    Line(sf::Vector2f position, sf::Vector2f end, sf::Color color);
    void draw(sf::RenderWindow &window) override;
    sf::FloatRect getBoundingBox() override;
    sf::Vector2f getPosition() override;
    void updatePosition(sf::Vector2f new_pos) override;
};

#endif  // _LINE_HPP_