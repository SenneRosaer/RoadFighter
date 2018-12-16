//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_SFMLBACKGROUND_H
#define ROADFIGHTER_SFMLBACKGROUND_H


#include "../roadfighter/Background.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace roadfighterSFML {
    class SFMLBackground : public roadfighter::Background {

    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
        SFMLBackground(const std::shared_ptr<sf::RenderWindow> &window);

        void draw() override;

        void update() override;
    };

}

#endif //ROADFIGHTER_SFMLBACKGROUND_H
