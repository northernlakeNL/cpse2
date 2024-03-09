#include "line.hpp"

/**
 * \brief De line constructor initialiseert een Line object met een gespecificeerde positie, eindpunt, kleur en
 * vertex array voor tekenen.
 * 
 * De `Line` constructor initialiseert een lijn object met een gespecificeerde positie, eindpunt, kleur en vertex
 * array voor tekenen. De constructor neemt een positie, eindpunt en kleur van de lijn als invoer. Het initialiseert
 * ook een vertex array voor het tekenen van de lijn.
 * 
 * @param position de `position` parameter stelt het startpunt van de lijn voor. Het is een `sf::Vector2f`
 * object dat de x- en y-coördinaten van het startpunt van de lijn bevat.
 * 
 * @param end De `end` parameter in de `Line` constructor stelt het eindpunt van het lijnsegment voor
 * dat zal worden getekend. Het is van het type `sf::Vector2f`, wat een 2D vector klasse is die wordt
 * geleverd door de SFML-bibliotheek voor het hanteren van 2D-coördinaten.
 * 
 * @param color De `color` parameter in de `Line` constructor is van het type `sf::Color`, wat een klasse
 * is die wordt geleverd door de SFML-bibliotheek voor het voorstellen van kleuren. Het wordt gebruikt om
 * de kleur van de lijn die zal worden getekend te specificeren.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Color](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Color.php)
 * @see [sf::Vertex](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vertex.php)
 * @see [sf::Lines](https://www.sfml-dev.org/documentation/2.6.1-fr/group__graphics.php#gga5ee56ac1339984909610713096283b1ba2bf015eeff9f798dfc3d6d744d669f1e)
 * 
 */
Line::Line(sf::Vector2f position, sf::Vector2f end, sf::Color color)
    : Object(position), end(end), color(color), lines(sf::Lines, 2) {
    lines[0] = sf::Vertex(position, color);
    lines[1] = sf::Vertex(position, color);
}

/**
 * \brief De functie `draw` tekent een lijn tussen twee punten op een `sf::RenderWindow` met behulp van
 * `sf::Vertex` en `sf::Lines`.
 * 
 * De `draw` functie tekent een lijn tussen twee punten op een `sf::RenderWindow` met behulp van
 * `sf::Vertex` en `sf::Lines`. Het maakt gebruik van de `sf::RenderWindow` parameter om de lijn op het
 * gespecificeerde venster te tekenen.
 * 
 * @param window de `sf::RenderWindow& window` parameter in de `draw` functie is een referentie naar een
 * SFML vensterobject. Deze parameter wordt gebruikt om de lijn op het gespecificeerde venster te tekenen.
 * 
 * @see [sf::Vertex](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vertex.php)
 * @see [sf::RenderWindow::draw](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a12417a3bcc245c41d957b29583556f39)
 */
void Line::draw(sf::RenderWindow& window) {
    sf::Vertex line[2] = {{position, color}, {end, color}}; // maak een lijn van startpunt naar eindpunt
    lines[0] = line[0];
    lines[1] = line[1];
    window.draw(line, 2, sf::Lines);
}

/**
 * \brief De functie `getPosition` retourneert de positie van een lijn als een 2D vector.
 * 
 * De `getPosition` functie retourneert de positie van een lijn als een 2D vector. Het retourneert
 * de positie van de linkerbovenhoek van de lijn.
 * 
 * @return Een `sf::Vector2f` object dat de positie van de lijn voorstelt.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
sf::Vector2f Line::getPosition() { return position; }

/**
 * \brief de functie `getBoundingBox` retourneert de begrenzende doos van een lijn in een C++ programma met behulp
 * van de SFML bibliotheek.
 * 
 * De `getBoundingBox` functie retourneert de begrenzende doos van een lijn in met behulp van de SFML bibliotheek.\
 * Het retourneert een `sf::FloatRect` object dat de begrenzende doos van het `Line`
 * object voorstelt.
 * 
 * @return Een `sf::FloatRect` object dat de begrenzende doos van het `Line` object voorstelt.
 *
 * @see [sf::FloatRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1FloatRect.php)
 */
sf::FloatRect Line::getBoundingBox() { return lines.getBounds(); }

/**
 * \brief de functie `updatePosition` werkt de positie van een lijn object bij en past het eindpunt
 * dienovereenkomstig aan.
 * 
 * De `updatePosition` functie werkt de positie van een lijn object bij en past het eindpunt dienovereenkomstig
 * aan. Het neemt een nieuwe positie als invoer en werkt de positie van de lijn bij. Het past ook het eindpunt van de
 * lijn aan op basis van de nieuwe positie.
 * 
 * @param new_pos De `new_pos` parameter is een `sf::Vector2f` die de nieuwe positie voorstelt waar de
 * lijn naartoe zal worden bijgewerkt.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
void Line::updatePosition(sf::Vector2f new_pos) {
    sf::Vector2f offset = new_pos - position;
    position = new_pos;
    end += offset;
}