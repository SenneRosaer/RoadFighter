//
// Created by senne on 12/21/18.
//

#ifndef ROADFIGHTER_SFMLPASSINGCAR_H
#define ROADFIGHTER_SFMLPASSINGCAR_H

#include "../roadfighter/PassingCar.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace roadfighterSFML {
    /**
     * Graphic side of passingcar
     */
class PassingCar : public roadfighter::PassingCar
{
private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;

public:

        /**
         * Constructor with window and a random value to determine the spawning location and configuration data
         * @param window
         * @param random
         * @param config
         *
         */
        PassingCar(const std::shared_ptr<sf::RenderWindow> window, double random, std::shared_ptr<ConfigData> config);

        /**
         * Draws the object
         */
        void draw() override;
};
} // namespace roadfighterSFML

#endif //ROADFIGHTER_PASSINGCAR_H
