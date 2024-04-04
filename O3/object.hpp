#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>

/**
 * \class Object
 * \brief De klasse `Object` is verantwoordelijk voor het maken van een object.
 * 
 * De klasse `Object` is een abstracte klasse die de basisfunctionaliteit biedt voor het maken van een object.
 * Het heeft een constructor die een positie als invoer neemt. Ook heeft het een functie om het object te
 * tekenen op een venster, een functie om de omtrek van het object te krijgen,
 * een functie om de positie van het object te krijgen, en een functie om de positie van het object bij te werken.
 * 
 * \note alle andere klassen die een object maken, moeten worden afgeleid van deze klasse.
 * \note De virtuele functies in deze klasse moeten worden geïmplementeerd in de subklassen.
 * \note Alle functies in deze klasse zijn virtueel.
 * 
*/
class Object {
   protected:
    sf::Vector2f position;

   public:
    Object(sf::Vector2f position) : position(position) {}
    virtual void draw(sf::RenderWindow &window);
    virtual sf::Vector2f getPosition();
    virtual sf::FloatRect getBoundingBox();
    virtual void updatePosition(sf::Vector2f new_pos);
};

#endif  // _OBJECT_HPP_
