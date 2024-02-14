#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Object.hpp"
#include "factory.hpp"

sf::Vector2f Vector2f_from_Vector2i( sf::Vector2i rhs ){
	return sf::Vector2f(
		static_cast< float >( rhs.x ),
		static_cast< float >( rhs.y )
	);
}

int main(){
    Factory factory;
    std::ifstream file("text.txt");
    std::string line;
    std::vector<std::string> lines;
    std::vector<Object*> objects;
    sf::Vector2f offset;
    Object* selected = nullptr;

    int screen_width = 1024;
    int screen_height = 768;

    std::cout << "Opdracht 1 starts" << std::endl;

    sf::Event event;
    sf::RenderWindow window( sf::VideoMode(screen_width,screen_height), "Opdracht 3");

    if (file.is_open()){
        while (getline(file, line)){
            lines.push_back(line);
        }
    }
    else{
        throw("unable to open text file!");
    }

    for (const auto& line : lines){
        Object* shape = factory.makeShape(line);
        if (shape != nullptr){
            objects.push_back(shape);
        }
    }

    while (window.isOpen()){
        window.clear();
        sf::Vector2f mouse_pos = Vector2f_from_Vector2i(sf::Mouse::getPosition(window));
        for (auto& object : objects) {
            if (object->getBoundingBox().intersects(sf::FloatRect(mouse_pos.x, mouse_pos.y, 1, 1))){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if (selected == nullptr){
                        selected = object;
                        offset = mouse_pos - selected->getPosition();
                    }
                }
            }
        }
        if (selected != nullptr){
            selected->updatePosition(mouse_pos - offset);
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            selected = nullptr;
        }

        for (auto& object : objects) {
            object->draw(window);
        }
        window.display();

        if( window.pollEvent(event) ){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}
