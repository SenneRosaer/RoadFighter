//
// Created by sennerosaer on 7/22/19.
//

#ifndef ROADFIGHTER_MENU_H
#define ROADFIGHTER_MENU_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "iostream"
class ConfigData;

/**
 * Menu class, handles the game menu and the level select
 */
class Menu {
private:
    std::shared_ptr<sf::RenderWindow> window;

    std::shared_ptr<ConfigData> config;
public:

    /**
     * Constructor with sfml window and configuration data
     * @param window
     * @param config
     */
    Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<ConfigData> config);

    /**
     * Draw the menu
     */
    void drawMenu();

    /**
     * Move up
     */
    void Up();
    /**
     * Move down
     */
    void Down();

    /**
     * Give back the selected item
     * @return integer
     */
    int GetSelected();


private:
    /**
     * Selected level to turn red
     */
    int selected = 0;

    /**
     * Used font
     */
    sf::Font font;

    /**
     * Text for every level
     */
    sf::Text text[3];
};


#endif //ROADFIGHTER_MENU_H
