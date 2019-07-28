//
// Created by sennerosaer on 7/22/19.
//

#ifndef ROADFIGHTER_MENU_H
#define ROADFIGHTER_MENU_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "iostream"


class Menu {
private:
    std::shared_ptr<sf::RenderWindow> window;
public:
    Menu(std::shared_ptr<sf::RenderWindow> window);
    void drawMenu();
    void Up();
    void Down();
    int GetSelected();


private:
    int selected = 0;
    sf::Font font;
    sf::Text text[4];
};


#endif //ROADFIGHTER_MENU_H
