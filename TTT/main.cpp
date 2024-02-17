#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "interact.hpp"
#include "line.hpp"
#include "command.hpp"
#include "object.hpp"

int main(){
    std::vector<std::vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool gui = false;
    bool terminal = false;

    std::cout << "Wilt u Terminal(T) of GUI(G)?" << std::endl;
    std::string option;
    std::cin >> option;

    if (option == "T" || option == "t"){
        terminal = true;
    }
    else if (option == "G" || option == "g"){
        gui = true;
    }

    sf::RenderWindow window( sf::VideoMode(900,900), "TicTacToe");

}