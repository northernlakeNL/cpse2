#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "factory.hpp"

/*!
 * \mainpage CPSE2 Opracht 3 Doxygen 
 * \section intro_sec Introduction
 * Dit is de documentatie voor mijn versie van CPSE2 Opdracht 3.
 * Ik heb dit gedocumenteerd zodat ik er later op terug kan kijken en goed kan zien wat er gedaan is.
 * 
 * \section classes_sec Classes
 * De volgende klassen zijn aanwezig in deze opdracht:
 * - Main
 *  - Factory
 *  - Object
 *   - Picture
 *   - Square
 *   - Line
 *   - Ball
 * 
 * \author Tom Noordermeer
 * \version 1.0
 * 
 *
 */


/**
 * \file main.cpp
 * \page main_cpp Main
 * \brief De main functie is het startpunt van het programma. Het programma maakt een venster aan en
 * tekent objecten op het scherm. De objecten worden ingeladen vanuit een bestand en worden
 * opgeslagen in een lijst. De objecten kunnen worden verplaatst door de muis te gebruiken.
 * 
 * @return De main functie geeft een integer terug, wat aangeeft of het programma succesvol is
 * 
 * \author Tom Noordermeer
 * 
*/

/**
 * De functie 'Vector2f_from_Vector2i' zet een `sf::Vector2i` om naar een `sf::Vector2f` door de
 * integer componenten naar float te casten.
 * 
 * @param rhs De parameter `rhs` is een object van type `sf::Vector2i`, wat een 2D vector voorstelt
 * met integer componenten `x` en `y`.
 * 
 * @return De functie geeft een `sf::Vector2f` object terug, wat gemaakt is door de `sf::Vector2i`
 * `rhs` om te zetten naar float waarden.
 * 
 * @see [sf::Vector2i](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 */
sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i rhs) {
    return sf::Vector2f(static_cast<float>(rhs.x), static_cast<float>(rhs.y));
}

/**
 * De main functie is het startpunt van het programma. Het programma maakt een venster aan en
 * tekent objecten op het scherm. De objecten worden ingeladen vanuit een bestand en worden
 * opgeslagen in een lijst. De objecten kunnen worden verplaatst door de muis te gebruiken.
 * 
 * @return De main functie geeft een integer terug, wat aangeeft of het programma succesvol is
 * 
 * @see [sf::RenderWindow](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderWindow.php)
 * @see [sf::Event](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Event.php)
 * @see [sf::Mouse](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Mouse.php)
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Vector2i](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::FloatRect](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1FloatRect.php)
 * @see [sf::RenderWindow::draw](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a12417a3bcc245c41d957b29583556f39)
 * @see [sf::RenderWindow::pollEvent](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Window.php#a338e996585faf82e93069858e3b531b7)
 * @see [sf::RenderWindow::close](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Window.php#a99d1e3e470f3b8f8feb1c16d0059d503)
 * @see [sf::RenderWindow::isOpen](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Window.php#a99d1e3e470f3b8f8feb1c16d0059d503)
 * @see [sf::RenderWindow::clear](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a6bb6f7c5d9e6c5f5f8c9a7e3c7f12a70)
 * @see [sf::RenderWindow::display](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1RenderTarget.php#a12417a3bcc245c41d957b29583556f39)
 * @see [sf::sleep](https://www.sfml-dev.org/documentation/2.6.1-fr/group__system.php#ga1a257d5d3443e1a15e1c3f8c3f0ce3b4)
 * @see [nullptr](https://en.cppreference.com/w/cpp/language/nullptr)
 * @see Factory
 * @see Object
 * 
*/
int main() {
    Factory factory;
    std::ifstream file;
    std::ofstream output;
    std::string line;
    std::vector<std::string> lines;
    std::vector<std::string> objectInfo;
    std::vector<Object*> objects;
    sf::Vector2f offset;
    Object* selected = nullptr;

    int screen_width = 1024;
    int screen_height = 768;

    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height),
                            "Opdracht 3");
    //Het bestand openen en lijn voor lijn in een lijs zetten
    file.open("shape_info.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    } else {
        throw("unable to open text file!");
    }
    file.close();

    //Voor elke regel in de lijnen, maak een vorm met de fabriek. 
    //Als de vorm niet niks is, voeg deze dan toe aan de objecten en voeg de string informatie toe aan objectInfo.
    for (const auto& line : lines) {
        Object* shape = factory.makeShape(line);
        if (shape != nullptr) {
            objects.push_back(shape);
            objectInfo.push_back(factory.getString(line));
        }
    }

    while (window.isOpen()) {
        window.clear();
        sf::Vector2f mouse_pos =
            Vector2f_from_Vector2i(sf::Mouse::getPosition(window));

        //dit stuk code checkt in een loop of de muis cursor zich bevindt in een objet en 
        //of de linker muisknop wordt ingedrukt
        //Als dit beide het geval is kan het object worden rond geschoven.
        //De positie wordt geupdate.
        //Als de muisknop wordt losgelaten wordt het object weer losgelaten.
        
        for (auto& object : objects) {
            if (object->getBoundingBox().intersects(
                    sf::FloatRect(mouse_pos.x, mouse_pos.y, 1, 1))) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (selected == nullptr) {
                        selected = object;
                        offset = mouse_pos - selected->getPosition();
                    }
                }
            }
        }
        if (selected != nullptr) {
            selected->updatePosition(mouse_pos - offset);
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            selected = nullptr;
        }
        //loop die de objecten tekent
        for (auto& object : objects) {
            object->draw(window);
        }

        window.display();

// Dit stuk code regelt de afhandelen van het sluiten van het scherm en het updaten van het document.
        if (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                output.open("shape_info.txt");
                for (unsigned int i = 0; i < objects.size(); i++) {
                    sf::Vector2f new_pos = objects[i]->getPosition();
                    output << "(" << new_pos.x << "," << new_pos.y << ") " << objectInfo[i] << std::endl;
                }
                output.close();
                window.close();
            }
        }
        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}
