//
// Created by sennerosaer on 8/8/19.
//

#ifndef ROADFIGHTER_SFMLBOSS_H
#define ROADFIGHTER_SFMLBOSS_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "memory"
#include "../roadfighter/Boss.h"

namespace roadfighterSFML {
    class Boss : public roadfighter::Boss {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
        /**
         * Draws the object
         */
        void draw() override;

        /**
         * Constructor with sfml window and configuration data
         * @param window
         * @param config
         */
        Boss(const std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<ConfigData> config);

    };
}


#endif //ROADFIGHTER_BOSS_H
