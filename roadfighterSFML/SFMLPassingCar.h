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
class PassingCar : public roadfighter::PassingCar {
        private:
            std::shared_ptr<sf::RenderWindow> window;
            sf::Sprite sprite;
            sf::Texture texture;

        public:
            PassingCar(const std::shared_ptr<sf::RenderWindow> window);

            //random meegegeven om dan aan het gewone object een spawn positie mee te geve
            PassingCar(const std::shared_ptr<sf::RenderWindow> window, double random);

    void draw() override;
};
}

#endif //ROADFIGHTER_SFMLPASSINGCAR_H
