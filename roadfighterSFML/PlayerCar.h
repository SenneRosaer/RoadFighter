//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_SFMLPLAYERCAR_H
#define ROADFIGHTER_SFMLPLAYERCAR_H

#include "../roadfighter/PlayerCar.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace roadfighterSFML {
    /**
     * Graphic side of the player class
     */
class PlayerCar : public roadfighter::PlayerCar
{
private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;

public:
        /**
         * Constructor with sfml window, current level and configuration data
         * @param window
         * @param level
         * @param config
         */
        PlayerCar(const std::shared_ptr<sf::RenderWindow> window, int level, std::shared_ptr<ConfigData> config);
        /**
         * Draws the player
         */
        void draw() override;

        /**
         * Updates the player
         */
        void update() override;
};
} // namespace roadfighterSFML

#endif //ROADFIGHTER_PLAYERCAR_H
