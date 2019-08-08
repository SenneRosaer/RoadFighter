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
    class SFMLBoss : public roadfighter::Boss {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
        void draw() override;

        SFMLBoss(const std::shared_ptr<sf::RenderWindow> window);

    };
}


#endif //ROADFIGHTER_SFMLBOSS_H
