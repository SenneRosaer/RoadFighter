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

class Game {
    private:

        std::shared_ptr<sf::RenderWindow> window;

        std::shared_ptr<roadfighter::World> world;

        std::shared_ptr<roadfighterSFML::SFMLFactory> factory;

    public:
    Game();

    void run();
};


#endif //ROADFIGHTER_GAME_H
