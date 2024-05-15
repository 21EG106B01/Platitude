#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <map>
#include "Building.h"
using namespace sf;

std::vector<Building> allBuildings = Building::createBuildingStore();

int main()
{
    //Game Window
    sf::Window window(sf::VideoMode(500, 500), "Platitude", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    //Game Loop
    while (window.isOpen()) {

        //Event Polling
        while (window.pollEvent(ev)) {


            if (ev.type == sf::Event::Closed)
                window.close();
        }
    }


    //End of Game
    return 0;
}

