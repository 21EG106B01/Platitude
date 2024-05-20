#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <string>
#include "Building.h"
#include "Button.h"
using namespace sf;

void pausemenu();
void clickDisappear(Button& btn, sf::RenderWindow& window);
std::string buildSelectorRadio(std::vector<Button*>& buildSelector, sf::RenderWindow& window);
std::vector<Building*> selectBuildings(std::string buildingtype);

int main()
{
    int width = 800;
    int height = 600;
    int block = 20;
    int mousex, mousey;

    std::string buildSelectorOn = "";

    //Game Window
    sf::RenderWindow window(sf::VideoMode(width, height), "Platitude", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    //Resources Declaration
    sf::Font lora_r;
    sf::Font kanit_r;
    sf::Font arial;
    sf::Texture backtex;
    sf::Texture interfaceBackTex;
    sf::Sprite backsprite;
    sf::Sprite interfaceBackSprite;
    std::vector<Building*> allBuildings;
    std::vector<Building*> selectedBuildings;
    std::vector<Button*> buildSelector;
    std::vector<sf::Sprite*> sprite_elements;
    std::vector<sf::Text*> text_elements;

    //Resources Definition
    backtex.loadFromFile("./resources/images/grass_background.jpg");
    backtex.setRepeated(true);
    backsprite.setTexture(backtex);
    backsprite.setTextureRect(sf::IntRect(0, 0, width * 4, height * 4));
    interfaceBackTex.loadFromFile("./resources/images/interface_background.png");
    interfaceBackSprite.setTexture(interfaceBackTex);
    lora_r.loadFromFile("./resources/fonts/Lora-Regular.ttf");
    kanit_r.loadFromFile("./resources/fonts/Kanit-Regular.ttf");
    arial.loadFromFile("./resources/fonts/Arial.ttf");
    allBuildings = Building::createBuildingStore();
    sprite_elements.push_back(&backsprite);
    sprite_elements.push_back(&interfaceBackSprite);

    //Element Initialization
    Button menubtn(674, 1, 74, 28, 15, "menubtn", "MENU  ", sprite_elements, text_elements, &lora_r);

    Button buildselectbtn1(32, 465, 114, 26, 15, "buildselectorbtn", "Residential", sprite_elements, text_elements, &kanit_r);
    Button buildselectbtn2(162, 465, 114, 26, 15, "buildselectorbtn", "Production", sprite_elements, text_elements, &kanit_r);
    Button buildselectbtn3(292, 465, 114, 26, 15, "buildselectorbtn", "Essential", sprite_elements, text_elements, &kanit_r);
    Button buildselectbtn4(422, 465, 114, 26, 15, "buildselectorbtn", "Utility", sprite_elements, text_elements, &kanit_r);
    buildSelector.push_back(&buildselectbtn1);
    buildSelector.push_back(&buildselectbtn2);
    buildSelector.push_back(&buildselectbtn3);
    buildSelector.push_back(&buildselectbtn4);

    sf::Text debugtext("", kanit_r, 20);
    debugtext.setPosition(25, height - 30);
    debugtext.setFillColor(sf::Color::Black);
    text_elements.push_back(&debugtext);

    //Game Loop
    while (window.isOpen()) {
        
        //Event Polling
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window.close();
            else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
                window.close();
        }
       
        //Show Mouse position
        mousex = sf::Mouse::getPosition(window).x;
        mousey = sf::Mouse::getPosition(window).y;
        debugtext.setString(std::to_string(mousex) + ", " + std::to_string(mousey));

        //Button presses
        if (ev.type == sf::Event::MouseButtonPressed or ev.type == sf::Event::MouseButtonReleased) {
            clickDisappear(menubtn, window); 
            if (ev.type == sf::Event::MouseButtonPressed) {
                buildSelectorOn = buildSelectorRadio(buildSelector, window);
                selectedBuildings = selectBuildings(buildSelectorOn);
            }
        }
        
        //Draw elements
        window.clear(sf::Color::Green);
        for(sf::Sprite* element : sprite_elements)
            window.draw(*element);
        for (sf::Text* element : text_elements)
            window.draw(*element);
        window.display();
    }

    //End of Game
    return 0;
}

void clickDisappear(Button& btn, sf::RenderWindow& window) {
    if (btn.isClicked(window))
        btn.setColor(sf::Color(0, 0, 0, 0));
    else
        btn.setColor(sf::Color(255, 255, 255, 255));
}

std::string buildSelectorRadio(std::vector<Button*>& buildSelector, sf::RenderWindow& window) {
    std::string content = "";
    for (Button* button : buildSelector) {
        if (button->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
            button->selected = true;
        }
        else {
            button->selected = false;
        }
    }
    for (Button* button : buildSelector) {
        if (button->selected == true){
            button->setColor(sf::Color(0, 0, 0, 0));
            content = button->getText();
        }
        else {
            button->setColor(sf::Color(255, 255, 255, 255));
        }
    }
    std::cout << "Content = " << content;
    return content;
}

std::vector<Building*> selectBuildings(std::string buildingtype) {
    std::vector<Building*> selectedBuilding;
    if (buildingtype == "Residential") {

    }
    else if (buildingtype == "Production") {

    }
    else if (buildingtype == "Essential") {

    }
    else if (buildingtype == "Utility") {

    }
}

void pausemenu() {

}