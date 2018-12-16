//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_SFMLPLAYERCAR_H
#define ROADFIGHTER_SFMLPLAYERCAR_H

#include <SFML/Graphics.hpp>
#include "../roadfighter/PlayerCar.h"
#include <memory>

namespace roadfighterSFML {
class PlayerCar : public roadfighter::PlayerCar {
        private:
            std::shared_ptr<sf::RenderWindow> window;
            sf::Sprite sprite;
            sf::Texture texture;


public:
            PlayerCar(const std::shared_ptr<sf::RenderWindow> window);

    void draw() override;

    void update() override;
};
}

#endif //ROADFIGHTER_SFMLPLAYERCAR_H
