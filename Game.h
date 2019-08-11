//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_GAME_H
#define ROADFIGHTER_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "roadfighter/Entity.h"
#include "roadfighter/World.h"
#include "roadfighterSFML/SFMLFactory.h"
#include "Observer/Subject.h"
#include "Menu.h"
#include "JSON/single_include/nlohmann/json.hpp"
#include "Scoreboard.h"
#include "ConfigData.h"
#include <fstream>


class Game {
    private:


        std::shared_ptr<sf::RenderWindow> window;

        std::shared_ptr<roadfighter::World> world;

        std::shared_ptr<roadfighterSFML::SFMLFactory> factory;

        std::shared_ptr<Menu> menu;

        std::shared_ptr<Scoreboard> scoreboard;

        std::shared_ptr<ConfigData> Config;







public:
    /**
     * Constructor
     */
    Game();

    /**
     * Runs the game
     * Updates the world and draws everything needed
     * Also creates the objects using a factory
     */
    void run();

    /**
     * Parses a file specified in the configuration file in which stands information about the level
     * @param level
     */
    void Parse(int level);

};


#endif //ROADFIGHTER_GAME_H
