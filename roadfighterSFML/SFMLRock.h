//
// Created by sennerosaer on 7/22/19.
//

#ifndef ROADFIGHTER_SFMLROCK_H
#define ROADFIGHTER_SFMLROCK_H

#include "SFML/Graphics.hpp"
#include "memory"
#include "../roadfighter/Rock.h"

namespace roadfighterSFML{
    class SFMLRock :  public roadfighter::Rock {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
        void draw() override;
        SFMLRock(std::shared_ptr<sf::RenderWindow> window,double i);

    };
}

#endif //ROADFIGHTER_SFMLROCK_H
