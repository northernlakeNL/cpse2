#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "square.hpp"
#include "object.hpp"
#include "hwlib.hpp"

struct square_action{
    sf::Keyboard::Key key;
    float x, y;
};

const square_action square_actions_P1 [] = {
    { sf::Keyboard::Up, 0, -1},
    { sf::Keyboard::Down, 0, 1}
};

const square_action square_actions_P2 [] = {
    { sf::Keyboard::W, 0, -1},
    { sf::Keyboard::S, 0, 1}
};


int main(){
    std::cout << "Opdracht 1 starts" << std::endl;

    sf::Vector2f speed = sf::Vector2f(1.5,1.5);
    sf::Event event;
    sf::RenderWindow window( sf::VideoMode(720,480), "Opdracht 1");

    ball new_ball(sf::Vector2f(110,70));
    square Player1(sf::Vector2f (600,169), sf::Vector2f(20,80), sf::Color(sf::Color::Cyan));
    square Player2(sf::Vector2f (100,169), sf::Vector2f(20,80), sf::Color(sf::Color::Magenta));
    square top_wall(sf::Vector2f (10,0), sf::Vector2f(700,10), sf::Color(sf::Color::White));
    square right_wall(sf::Vector2f (710,10), sf::Vector2f(10,460), sf::Color(sf::Color::Blue));
    square left_wall(sf::Vector2f (0,10), sf::Vector2f(10,460), sf::Color(sf::Color::Blue));
    square bottom_wall(sf::Vector2f (10,470), sf::Vector2f(700,10), sf::Color(sf::Color::White));


    std::vector<Object*> objects = { &new_ball, &Player1, &Player2, &top_wall, &right_wall, &left_wall, &bottom_wall};

    while (window.isOpen()) {

        for(auto& square_action : square_actions_P1) {
            if (sf::Keyboard::isKeyPressed (square_action.key)) {
                Player1.move(sf::Vector2f(square_action.x, square_action.y));
            }
        }

        for(auto& square_action : square_actions_P2) {
            if (sf::Keyboard::isKeyPressed (square_action.key)) {
                Player2.move(sf::Vector2f(square_action.x, square_action.y));
            }
        }

        speed = new_ball.collision({objects.begin()+1, objects.end()}, speed);

        new_ball.move(speed);
        
        window.clear();

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