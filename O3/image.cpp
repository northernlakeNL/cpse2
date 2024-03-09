#include "image.hpp"

/**
 * De functie `Picture::Picture` is een constructor voor de klasse `Picture` die de positie en
 * het pad initialiseert.
 * 
 * @param pos De `pos` parameter in de `Picture` constructor is van het type `sf::Vector2f`, wat
 * een 2D-vector met floating point-coördinaten voorstelt. Het wordt gebruikt om de positie van het
 * afbeeldingsobject op het scherm te specificeren.
 * @param path De `path` parameter in de `Picture` constructor is een `std::string` die het bestandspad
 * naar de afbeelding voorstelt die zal worden weergegeven door het `Picture` object. Dit pad wordt
 * gebruikt om de afbeelding van het bestandssysteem te laden en op het scherm te renderen op de
 * gespecificeerde positie.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
Picture::Picture(sf::Vector2f pos, std::string path)
    : Object(pos), path(path) {}

/**
 * De functie `draw` laadt een afbeelding uit een bestand, stelt het in als een textuur voor een
 * sprite, positioneert de sprite en tekent deze op een venster met behulp van SFML.
 * 
 * @param window De `sf::RenderWindow& window` parameter is een referentie naar het vensterobject van de
 * SFML-bibliotheek. Deze parameter wordt gebruikt in de `draw` functie om het `sprite` object op het
 * venster te renderen.
 * 
 * @see [sf::RenderWindow](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderWindow.php)
 * @see [sf::Sprite](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Sprite.php)
 * @see [sf::Texture](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Texture.php)
 * @see [sf::Texture::loadFromFile](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Texture.php#a4c6b08a0a6b7b3e8b1e6c2d3d5f7c3b0)
 * @see [sf::Sprite::setTexture](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Sprite.php#a3729c88d88ac38c193a392e7cd22f0a8)
 * @see [sf::Sprite::setPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#af1a42209ce2b5d3f07b00f917bcd8015)
 * @see [sf::RenderWindow::draw](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a12417a3bcc245c41d957b29583556f39)
 */
void Picture::draw(sf::RenderWindow& window) {
    image.loadFromFile(path);
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
}

/**
 * De functie `getBoundingBox` retourneert een `sf::FloatRect` die de omlijning van een `Picture`
 * object voorstelt op basis van de positie en de afmetingen van de sprite.
 * 
 * @return De functie retourneert een `sf::FloatRect` object dat de omlijning van
 * een `Picture` object voorstelt. De omlijning wordt berekend op basis van de positie van de afbeelding
 * en de afmetingen van de sprite textuur rechthoek.
 * 
 * @see [sf::FloatRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1FloatRect.php)
 * @see [sf::Sprite::getTextureRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Sprite.php#a3c4fb1c94cf7bcf5e8f4d805b79f8f4e)
 * @see [sf::Sprite::getPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#af1a42209ce2b5d3f07b00f917bcd8015)
 * @see [sf::Sprite::getGlobalBounds](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Sprite.php#a5d6e5f8e9af0c1b8f7c6f872db73f61b)
 * @see [sf::FloatRect::FloatRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1FloatRect.php#a4b1e0d1b7f587e41c7d0e4b8f870d6e7)
 */
sf::FloatRect Picture::getBoundingBox() {
    sf::IntRect sprite_rect_int = sprite.getTextureRect();
    return sf::FloatRect(static_cast<float>(position.x),
                         static_cast<float>(position.y),
                         static_cast<float>(position.x + sprite_rect_int.width),
                         static_cast<float>(position.y + sprite_rect_int.height));
}

/**
 * De functie `getPosition` retourneert de positie van de sprite in een `sf::Vector2f` formaat.
 * 
 * @return De functie retourneert een `sf::Vector2f` object dat de positie van de sprite voorstelt.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Sprite::getPosition](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Transformable.php#aea8b18e91a7bf7be589851bb9dd11241)
 */
sf::Vector2f Picture::getPosition() { return sprite.getPosition(); }

/**
 * De functie `updatePosition` werkt de positie van de sprite bij op basis van een nieuwe positie
 * invoer.
 * 
 * @param new_pos De `new_pos` parameter is een `sf::Vector2f` object dat de nieuwe positie van de
 * sprite voorstelt.
 * 
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
void Picture::updatePosition(sf::Vector2f new_pos) {
    position = new_pos;
}