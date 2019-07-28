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
class SFMLBackground : public roadfighter::Background
{

private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::RectangleShape BG1;
        sf::RectangleShape BG2;
        sf::RectangleShape BG3;

        sf::Texture texture;

public:
        /**
         * Constructor with window
         * @param window
         */
        SFMLBackground(const std::shared_ptr<sf::RenderWindow>& window, int type);

        /**
         * Draws the background
         */
        void draw() override;
};

} // namespace roadfighterSFML

#endif // ROADFIGHTER_SFMLBACKGROUND_H
