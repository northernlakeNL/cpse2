#include "square.hpp"

#include <SFML/Graphics.hpp>

/**
 * \brief De functie `Square::Square` initialiseert een vierkant object met een gespecificeerde positie,
 * grootte en kleur.
 * 
 * De `Square` constructor initialiseert een vierkant object met een gespecificeerde positie, grootte en kleur.
 * Het heeft een parameter `pos` van het type `sf::Vector2f` die de positie van het vierkant voorstelt, een
 * parameter `size` van het type `sf::Vector2f` die de afmetingen van het vierkant voorstelt, en een parameter
 * `color` van het type `sf::Color` die de kleur van het vierkant voorstelt.
 * 
 * @param pos De parameter `pos` is een `sf::Vector2f` die de positie van het vierkant voorstelt.
 * @param size De parameter `size` in de constructor van `Square` stelt de afmetingen van het vierkant
 * object dat wordt gemaakt voor. Het is van het type `sf::Vector2f`, dat een 2D vector klasse is die
 * wordt geleverd door de SFML bibliotheek. Deze vector bevat de breedte en hoogte van het vierkant.
 * @param color De parameter `color` is van het type `sf::Color`, dat een klasse is die wordt geleverd
 * door de SFML bibliotheek voor het voorstellen van kleuren. Het wordt gebruikt om de kleur van het
 * vierkant object dat wordt gemaakt te specificeren.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Color](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Color.php)
 */
Square::Square(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
    : Object(pos), size(size), color(color), rect(size) {}

/**
 * \brief De functie `draw` gebruikt de SFML bibliotheek om een vierkant op een venster te tekenen.
 * 
 * De `draw` functie gebruikt de SFML bibliotheek om een vierkant op een venster te tekenen. Het maakt
 * gebruik van de `sf::RenderWindow` parameter om het vierkant op het gespecificeerde venster te tekenen.
 * 
 * @param window De `sf::RenderWindow& window` parameter in de `draw` functie is een referentie naar een
 * SFML venster object. Deze parameter wordt gebruikt om het vierkant object op het gespecificeerde
 * SFML venster te tekenen.
 * 
 * @see [sf::RenderWindow](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderWindow.php)
 * @see [sf::RectangleShape::setPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#af1a42209ce2b5d3f07b00f917bcd8015)
 * @see [sf::RectangleShape::setFillColor](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Shape.php#aa5da23e522d2dd11e3e7661c26164c78)
 * @see [sf::RenderWindow::draw](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a12417a3bcc245c41d957b29583556f39)
 */
void Square::draw(sf::RenderWindow& window) {
    rect.setPosition(position);
    rect.setFillColor(color);
    window.draw(rect);
}

/**
 * \brief De functie `getBoundingBox` retourneert de globale omtrek van een vierkant object.
 * 
 * De `getBoundingBox` functie retourneert de globale omtrek van een vierkant object. Het retourneert
 * een `sf::FloatRect` object dat de omtrek van het vierkant object voorstelt.
 * 
 * @return Een `sf::FloatRect` object dat de omtrek van het vierkant object voorstelt, wordt geretourneerd.
 * 
 * @see [sf::FloatRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1FloatRect.php)
 * @see [sf::RectangleShape::getGlobalBounds](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Shape.php#ac0e29425d908d5442060cc44790fe4da)
 */
sf::FloatRect Square::getBoundingBox() { return rect.getGlobalBounds(); }

/**
 * \brief De functie `getPosition` retourneert de positie van een vierkant object.
 * 
 * De `getPosition` functie retourneert de positie van een vierkant object. Het retourneert een `sf::Vector2f`
 * object dat de positie van het vierkant voorstelt.
 * 
 * @return Een `sf::Vector2f` object dat de positie van het vierkant object voorstelt, wordt geretourneerd.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::RectangleShape::getPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#aea8b18e91a7bf7be589851bb9dd11241)
 */
sf::Vector2f Square::getPosition() { return rect.getPosition(); }

/**
 * \brief De functie `updatePosition` werkt de positie van een vierkant object bij.
 * 
 * De `updatePosition` functie werkt de positie van een vierkant object bij op basis van een nieuwe positie
 * invoer.
 * 
 * @param new_pos De `new_pos` parameter is een `sf::Vector2f` die de nieuwe positie van het vierkant
 * object voorstelt.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
void Square:: updatePosition(sf::Vector2f new_pos) { 
    position = new_pos; 
    }