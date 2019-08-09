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
         * Constructor with sfml window
         * @param window
         */
        MovingCar(const std::shared_ptr<sf::RenderWindow> window);

        /**
         * Constructor with window and a random value to determine the spawning location
         * @param window
         * @param random
         */
        MovingCar(const std::shared_ptr<sf::RenderWindow> window, double random);

        void draw() override;
    };
}


#endif //ROADFIGHTER_MOVINGCAR_H
