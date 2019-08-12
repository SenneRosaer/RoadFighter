//
// Created by sennerosaer on 7/23/19.
//

#ifndef ROADFIGHTER_SFMLMOVINGCAR_H
#define ROADFIGHTER_SFMLMOVINGCAR_H

#include "SFML/Graphics.hpp"
#include "memory"
#include "../roadfighter/MovingCar.h"

namespace roadfighterSFML {
class MovingCar: public roadfighter::MovingCar {
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
         */
        MovingCar(const std::shared_ptr<sf::RenderWindow> window, double random, std::shared_ptr<ConfigData> config);

        /**
         * draws the object
         */
        void draw() override;
    };
}


#endif //ROADFIGHTER_MOVINGCAR_H
