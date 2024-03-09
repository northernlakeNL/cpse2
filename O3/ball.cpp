#include "ball.hpp"

#include <SFML/Graphics.hpp>

/**
 * De functie `Ball::Ball` initialiseert een `Ball` object met een gespecificeerde positie, grootte en kleur.
 * 
 * @param pos De parameter `pos` is van het type `sf::Vector2f` en stelt de positie van de bal voor in
 * 2D-ruimte. Het bevat de x- en y-coördinaten van de positie van de bal.
 * @param size De parameter `size` in de `Ball` constructor stelt de diameter van het bal object voor.
 * Het bepaalt hoe groot het bal object zal verschijnen op het scherm.
 * @param color De parameter `color` is van het type `sf::Color`, wat een klasse is die wordt
 * geleverd door de SFML-bibliotheek voor het voorstellen van kleuren. Het wordt gebruikt om de kleur
 * van het bal object dat wordt gemaakt te specificeren.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Color](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Color.php)
 */
Ball::Ball(sf::Vector2f pos, float size, sf::Color color)
    : Object(pos), size(size), color(color) {}

/**
 * De functie `draw` in C++ tekent een cirkel die een bal voorstelt op een gegeven `sf::RenderWindow` venster.
 * 
 * @param window De `sf::RenderWindow& window` parameter is een referentie naar het vensterobject waar de
 * bal zal worden getekend. Deze parameter maakt het mogelijk voor de `draw` functie om de bal te renderen
 * op het gespecificeerde venster.
 * 
 * @see [sf::circleShape::setRadius](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1CircleShape.php#a21cdf85fc2f201e10222a241af864be0)
 * @see [sf::circleShape::setPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#a4dbfb1a7c80688b0b4c477d706550208)
 * @see [sf::circleShape::setFillColor](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Shape.php#a3506f9b5d916fec14d583d16f23c2485)
 * @see [sf::RenderWindow::draw](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a12417a3bcc245c41d957b29583556f39)
 */
void Ball::draw(sf::RenderWindow& window) {
    circle.setRadius(size);
    circle.setPosition(position);
    circle.setFillColor(color);
    window.draw(circle);
}

/**
 * De functie `getBoundingBox` in C++ retourneert de globale begrenzende rechthoek van een cirkelobject.
 * 
 * @return een `sf::FloatRect` object dat de begrenzende rechthoek van de cirkelvormige vorm voorstelt.
 * 
 * @see [sf::FloatRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1FloatRect.php)
 * @see [sf::circleShape::getGlobalBounds](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Shape.php#ac0e29425d908d5442060cc44790fe4da)
 */
sf::FloatRect Ball::getBoundingBox() { return circle.getGlobalBounds(); }

/**
 * De functie `getPosition` in C++ retourneert de positie van een bal object als een `sf::Vector2f`.
 * 
 * @return Een `sf::Vector2f` die de positie van de bal voorstelt, die wordt verkregen uit de positie
 * van de cirkel.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::circleShape::getPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#af1a42209ce2b5d3f07b00f917bcd8015)
 */
sf::Vector2f Ball::getPosition() { return circle.getPosition(); }

/**
 * De functie `updatePosition` in C++ werkt de positie van een bal object bij op basis van een nieuwe
 * positie invoer.
 * 
 * @param new_pos De `new_pos` parameter is een `sf::Vector2f` object dat de nieuwe positie van de bal
 * voorstelt.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
void Ball::updatePosition(sf::Vector2f new_pos) {
    position = new_pos;
}