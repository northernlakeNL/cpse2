#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "Object.hpp"
#include "ball.hpp"
#include "image.hpp"
#include "line.hpp"
#include "square.hpp"

/**
 * \class Factory
 * \brief De klasse `Factory` is verantwoordelijk voor het maken van objecten van de klasse `Object` en het
 * extraheren van parameters voor het maken van verschillende vormen zoals Rechthoek, Lijn, Cirkel of
 * Afbeelding. Afhankelijk van het type vorm dat is gespecificeerd in de invoerregel, maakt de functie
 * een object van de overeenkomstige vormklasse en geeft dit terug. Als het type vorm is
 * gespecificeerd in de invoerregel niet wordt herkend, wordt er een foutmelding afgedrukt naar
 * `std::cerr` en wordt `nullptr` teruggegeven.
 * 
 * @see Factory::getColor
 * @see Factory::makeUpper
 * @see Factory::makeShape
 * @see Factory::getString
*/
class Factory {
   public:
    Factory() = default;
    sf::Color getColor(std::string);
    Object* makeShape(std::string line);
    std::string makeUpper(std::string link);
    std::string getString(std::string line);
};