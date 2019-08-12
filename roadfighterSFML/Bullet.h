//
// Created by senne on 1/16/19.
//

#ifndef ROADFIGHTER_SFMLBULLET_H
#define ROADFIGHTER_SFMLBULLET_H

#include "../roadfighter/Bullet.h"
#include <SFML/Graphics.hpp>

namespace roadfighterSFML {
class Bullet : public roadfighter::Bullet
{
private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;

public:
        /**
         * Draws the bullet
         */
        void draw() override;

        /**
         * Constructor with a window and the position and configuration data
         * @param window
         * @param first
         * @param second
         * @param config
         */
        Bullet(const std::shared_ptr<sf::RenderWindow> window, double first, double second, std::shared_ptr<ConfigData> config);
};
} // namespace roadfighterSFML

#endif //ROADFIGHTER_BULLET_H
