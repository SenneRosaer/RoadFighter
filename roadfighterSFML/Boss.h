//
// Created by sennerosaer on 8/8/19.
//

#ifndef ROADFIGHTER_SFMLBOSS_H
#define ROADFIGHTER_SFMLBOSS_H

#include "../roadfighter/Boss.h"
#include "SFML/Graphics.hpp"
#include "memory"
#include <iostream>

namespace roadfighterSFML {
/**
 *Graphic side of the boss
 */
class Boss : public roadfighter::Boss
{
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
} // namespace roadfighterSFML

#endif // ROADFIGHTER_BOSS_H
