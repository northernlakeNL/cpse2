#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "interact.hpp"
#include "line.hpp"
#include "command.hpp"
#include "object.hpp"
#include "line.hpp"

int main(){
    std::vector<std::vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool gui = false, terminal = false, no_choice = true, player1 = true, player2 = false;
    std::string option, choice;

    while (no_choice){
        std::cout << "Wilt u Terminal(T) of GUI(G)?" << std::endl;
        std::cin >> option;

        if (option == "T" || option == "t"){
            terminal = true;
            no_choice = false;
        }
        else if (option == "G" || option == "g"){
            gui = true;
            no_choice = false;
        }
        else{
            std::cerr << "U heeft geen geldige optie gekozen" << std::endl;
        }
    }

    while (terminal){
        int placement = 1;
        for (auto& row: board){
            for (auto& cell: row){
                std::cout << " " << cell << " ";
                if (&cell != &row.back()){
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
        }
        if (player1){
            std::cout << "Speler 1 (O), kies een positie (1-9): ";
            std::cin >> choice;
            for (auto& row: board){
                for (unsigned int i = 0; i < row.size(); i++){
                    if (choice == std::to_string(placement)){
                        if (row[i] == ' '){
                            row[i] = 'O';
                            player2 = true;
                            player1 = false;    
                        }
                    }
                    placement++;
                }
            }

        }
        else if (player2){
            std::cout << "Speler 2 (X), kies een positie (1-9): "; 
            std::cin >> choice;
            for (auto& row: board){
                for (unsigned int i = 0; i < row.size(); i++){
                    if (choice == std::to_string(placement)){
                        if (row[i] == ' '){
                            row[i] = 'X';
                            player1 = true;
                            player2 = false;
                        }
                    }
                    placement++;
                }
            }

        }

    }

    if (gui){
        sf::Event event;
        sf::RenderWindow window( sf::VideoMode(900,1100), "TicTacToe");
        
        Line line(sf::Vector2f(0,200), sf::Vector2f(900,10), sf::Color::White);
        Line line1(sf::Vector2f(300,200), sf::Vector2f(10,900), sf::Color::White);
        Line line2(sf::Vector2f(600,200), sf::Vector2f(10,900), sf::Color::White);
        Line line3(sf::Vector2f(0,500), sf::Vector2f(900,10), sf::Color::White);
        Line line4(sf::Vector2f(0,800), sf::Vector2f(900,10), sf::Color::White);

        std::vector<Object*> objects = {&line, &line1, &line2, &line3, &line4};

        while (gui){
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
            }
            window.clear();
            for (auto& object: objects){
                object->draw(window);
            }
            window.display();
        }
    }

}