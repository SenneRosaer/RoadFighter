//
// Created by sennerosaer on 7/22/19.
//

#ifndef ROADFIGHTER_SFMLROCK_H
#define ROADFIGHTER_SFMLROCK_H

#include "SFML/Graphics.hpp"
#include "memory"
#include "../roadfighter/Rock.h"

namespace roadfighterSFML{
    class Rock : public roadfighter::Rock {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
        void draw() override;
        Rock(std::shared_ptr<sf::RenderWindow> window, double i, std::shared_ptr<ConfigData> config);

    };
}

#endif //ROADFIGHTER_ROCK_H
