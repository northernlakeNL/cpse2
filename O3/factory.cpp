#include "factory.hpp"

/**
 * De functie `getColor` geeft een `sf::Color` object terug, gebaseerd op de input string `color`, of
 * geeft een foutmelding als de kleur niet herkend wordt.
 * 
 * @param color de `getColor` functie neemt een `std::string` parameter genaamd `color`, wat de
 * kleurnaam voorstelt die de functie zal gebruiken om de corresponderende `sf::Color` object te
 * bepalen en terug te geven.
 * 
 * @return Als de input color overeenkomt met een van de vooraf gedefinieerde kleuren ("RED", "BLUE",
 * "YELLOW", "GREEN", "WHITE"), dan wordt de corresponderende `sf::Color` waarde teruggegeven. Als de
 * input color niet overeenkomt met een van deze vooraf gedefinieerde kleuren, wordt er een foutmelding
 * afgedrukt naar `std::cerr` en wordt `sf::Color::Transparent` teruggegeven.
 * 
 * @see sf::Color
 */
sf::Color Factory::getColor(std::string color) {
    if (color == "RED") {
        return sf::Color::Red;
    } else if (color == "BLUE") {
        return sf::Color::Blue;
    } else if (color == "YELLOW") {
        return sf::Color::Yellow;
    } else if (color == "GREEN") {
        return sf::Color::Green;
    } else if (color == "WHITE") {
        return sf::Color::White;
    } else {
        std::cerr << "Color " << color << " not recognized" << std::endl;
    }
    return sf::Color::Transparent;
}


/**
 * De functie `makeUpper` in de `Factory` klasse zet een gegeven string om naar hoofdletters.
 * 
 * @param type De functie neemt een `std::string` parameter genaamd `type` en zet alle
 * karakters in de string om naar hoofdletters met behulp van `std::toupper`.
 * 
 * @return de functie geeft een nieuwe `std::string` terug waarin alle karakters in de
 * input `type` string zijn omgezet naar hoofdletters met behulp van `std::toupper`.
 */
std::string Factory::makeUpper(std::string type) {
    for (auto& c : type) {
        c = std::toupper(c);
    }
    return type;
}


/**
 * De functie `makeShape` in de `Factory` klasse analyseert een string invoer om verschillende soorten
 * vormen te maken op basis van de verstrekte parameters.
 * 
 * @param line De functie neemt een string `line` als invoer, wat een tekstregel
 * voorstelt met informatie over een vorm die moet worden gemaakt. Er wordt verwacht dat de regel een
 * specifieke opmaak heeft en waarden bevat die gescheiden zijn door spaties.
 * 
 * @return De functie geeft een dynamisch toegewezen object van een specifieke vormklasse
 * terug op basis van de verstrekte invoerregel. De functie analyseert de invoerregel om de nodige
 * parameters te extraheren voor het maken van verschillende vormen zoals Rechthoek, Lijn, Cirkel of
 * Afbeelding. Afhankelijk van het type vorm dat is gespecificeerd in de invoerregel, maakt de functie
 * een object van de overeenkomstige vormklasse en geeft dit terug. Als het type vorm is
 * gespecificeerd in de invoerregel niet wordt herkend, wordt er een foutmelding afgedrukt naar
 * `std::cerr` en wordt `nullptr` teruggegeven.
 * 
 * @see Factory::getColor
 * @see Factory::makeUpper
 * @see square
 * @see Line
 * @see Ball
 * @see Picture
 * @see Object
 * @see [sf::Vector2f](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Vector2.php)
 * @see [sf::Color](https://www.sfml-dev.org/documentation/2.6.1-fr/classsf_1_1Color.php)
 */
Object* Factory::makeShape(std::string line) {
    std::replace(line.begin(), line.end(), '(', ' ');
    std::replace(line.begin(), line.end(), ')', ' ');
    std::replace(line.begin(), line.end(), ',', ' ');

    std::istringstream iss(line);  // split de lijn waar er een spatie voorkomt

    float x, y, width, height;
    std::string color, type;

    iss >> x >> y >> type;  // volgorde van de lijn in values zetten (in het geval van x en y
               // gebeurt het splitten bij de komma)

    type = makeUpper(type); // maak de type string hoofdletters, zodat het niet uitmaakt of de gebruiker hoofdletters of kleine letters gebruikt

    if (type == "RECTANGLE") {
        iss >> color >> width >> height;
        color = makeUpper(color);
        return new Square(sf::Vector2f(x, y), sf::Vector2f(width, height),
                          getColor(color));
    } else if (type == "LINE") {
        float x2, y2;
        iss >> color >> x2 >> y2;
        color = makeUpper(color);
        return new Line(sf::Vector2f(x, y), sf::Vector2f(x2, y2),
                        getColor(color));
    } else if (type == "CIRCLE") {
        float radius;
        iss >> color >> radius;
        color = makeUpper(color);
        return new Ball(sf::Vector2f(x, y), radius, getColor(color));
    } else if (type == "PICTURE") {
        std::string link;
        iss >> link;
        return new Picture(sf::Vector2f(x, y), link);
    } else {
        std::cerr << "unsupported shape in line: " << line << std::endl
                  << "check Shape: " << type << std::endl;
    }
    return nullptr;
}

/**
 * De functie `getString` in de `Factory` klasse analyseert een string invoer om de informatie over
 * een vorm te extraheren en terug te geven als een nieuwe string.
 * 
 * @param line De functie neemt een string `line` als invoer, wat een tekstregel
 * voorstelt met informatie over een vorm die moet worden gemaakt. Er wordt verwacht dat de regel een
 * specifieke opmaak heeft en waarden bevat die gescheiden zijn door spaties.
 * 
 * @return De functie geeft een nieuwe string terug die de informatie over de vorm
 * bevat, zoals het type vorm, de kleur, en de grootte. De functie analyseert de invoerregel om de
 * nodige parameters te extraheren voor het maken van de nieuwe string. De nieuwe string bevat de
 * informatie over de vorm, zoals het type vorm, de kleur, en de grootte, en wordt teruggegeven.
*/
std::string Factory::getString(std::string line) {
    std::string position, type, info, size;
    std::istringstream iss(line);  // split de lijn waar er een spatie voorkomt
    iss >> position >> type >> info >> size; // x en y worden hier niet gebruikt
    std::string returnString = type + " " + info + " " + size;

    return returnString;
}