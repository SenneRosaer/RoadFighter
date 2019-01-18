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
class PassingCar : public roadfighter::PassingCar
{
private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;

public:
        /**
         * Constructor with sfml window
         * @param window
         */
        PassingCar(const std::shared_ptr<sf::RenderWindow> window);

        /**
         * Constructor with window and a random value to determine the spawning location
         * @param window
         * @param random
         */
        PassingCar(const std::shared_ptr<sf::RenderWindow> window, double random);

        void draw() override;
};
} // namespace roadfighterSFML

#endif // ROADFIGHTER_SFMLPASSINGCAR_H
