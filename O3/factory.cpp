#include "factory.hpp"

sf::Color Factory::getColor(std::string color){
    if (color == "red"){ return sf::Color::Red;}
    else if (color == "blue"){ return sf::Color::Blue;}
    else if (color == "yellow"){ return sf::Color::Yellow;}
    else if (color == "green"){ return sf::Color::Green;}
    else if (color == "white"){ return sf::Color::White;}
    else {
        std::cerr << "Color " << color << " not recognized" << std::endl;
    }
    return sf::Color::Black;
}

std::string Factory::makeUpper(std::string type){
    for (auto& c : type){
        c = std::toupper(c);
    }
    return type;
}


/*----SStream beredenering----
ik gebruik sstream om de zin te splitten en dit gemakkelijk in waarden te kunnen zetten.
sstream heeft als functie de zin per karakter te bekijken als de karakter geen cijfer of letter is, wordt hier de scheiding gemaakt en kan dit in een value gestopt worden.
dit gebeurt bij spaties, komma's en andere niet nummerike of alfabetische karakters.
*/

Object* Factory::makeShape(std::string line){
    std::replace(line.begin(), line.end(), '(', ' ');
    std::replace(line.begin(), line.end(), ')', ' ');
    std::replace(line.begin(), line.end(), ',', ' ');

    std::istringstream iss(line); //split de lijn waar er een spatie voorkomt

    float x, y, width, height;
    std::string color, type;

    iss >> x >> y >> type; // volgorde van de lijn in values zetten (in het geval van x en y gebeurt het splitten bij de komma)

    type = makeUpper(type);

    if (type == "RECTANGLE" || type == "LINE"){
        iss >> color >> width >> height;
        return new square(sf::Vector2f(x,y), sf::Vector2f(width,height), getColor(color));
    }
    else if( type == "CIRCLE"){
        float radius;
        iss >> color >> radius;
        return new ball(sf::Vector2f(x,y), radius, getColor(color));
    }
    else if( type == "PICTURE"){
        std::string link;
        iss >> link;
        std::cout << link << std::endl;
        return new Picture(sf::Vector2f(x,y), link);
    }
    else{
        std::cerr << "unsupported shape in line: " << line << std::endl << "check Shape: " << type << std::endl;
    }
    return nullptr;
}