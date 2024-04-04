#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "object.hpp"


/**
 * \class Picture
 * \brief De klasse `Picture` is een subklasse van de klasse `Object` en stelt een afbeelding voor die kan worden
 * getekend op een `sf::RenderWindow` venster. De klasse bevat een pad naar een afbeeldingsbestand, een
 * `sf::Texture` object en een `sf::Sprite` object. Het heeft een constructor die een positie en een
 * pad naar een afbeeldingsbestand verwacht. Ook heeft het een `draw` functie die de afbeelding
 * tekent op een gegeven venster, een `getBoundingBox` functie die de begrenzende rechthoek van de afbeelding
 * retourneert, een `getPosition` functie die de positie van de afbeelding retourneert en een `updatePosition`
 * functie die de positie van de afbeelding bijwerkt.
 * 
 * \note De positie is de positie van de linkerbovenhoek van de afbeelding.
 * 
 * @see Object
*/
class Picture : public Object {
private:
    std::string path;
    sf::Texture image;
    sf::Sprite sprite;

public:
    Picture(sf::Vector2f pos, std::string path);
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBoundingBox() override;
    sf::Vector2f getPosition() override;
    void updatePosition(sf::Vector2f new_pos) override;
};