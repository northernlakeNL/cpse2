#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.hpp"

/**
 * \class Ball
 * \brief De klasse `ball` is verantwoordelijk voor het maken van een cirkelvormig object.
 * 
 * Deze klasse is een subklasse van de klasse `Object`. De klasse heeft een cirkelvormig
 * object met een bepaalde grootte en kleur. Het heeft een constructor die een positie,
 * grootte en kleur van de cirkel als invoer neemt. Ook heeft het een functie om de
 * cirkel te tekenen op een venster, een functie om de omtrek van de cirkel te krijgen, een functie
 * om de positie van de cirkel te krijgen, en een functie om de positie van de cirkel bij te werken.
 * 
 * \note De positie is de positie van de linkerbovenhoek van de cirkel.
 * 
 * @see ball::ball
 * @see ball::draw
 * @see ball::getBoundingBox
 * @see ball::getPosition
 * @see ball::updatePosition
 * @see Object
 */
class Ball : public Object {
   private:
    float size;
    sf::Color color;
   public:
    sf::CircleShape circle;
    Ball(sf::Vector2f pos, float size, sf::Color color);
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBoundingBox() override;
    sf::Vector2f getPosition() override;
    void updatePosition(sf::Vector2f new_pos) override;
};

#endif