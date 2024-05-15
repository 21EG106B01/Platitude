#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <map>
#include "Building.h"
using namespace sf;


int main()
{
    //Game Window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Platitude", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;


    std::vector<Building> allBuildings = Building::createBuildingStore();
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //Game Loop
    while (window.isOpen()) {

        //Event Polling
        while (window.pollEvent(ev)) {


            if (ev.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }


    //End of Game
    return 0;
}

