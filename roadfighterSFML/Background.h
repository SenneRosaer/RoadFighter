//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_SFMLBACKGROUND_H
#define ROADFIGHTER_SFMLBACKGROUND_H

#include "../roadfighter/Background.h"
#include "../Observer/Observer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace roadfighterSFML {
class Background : public roadfighter::Background
{

private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::RectangleShape BG1;
        sf::RectangleShape BG2;
        sf::RectangleShape BG3;

        sf::Texture texture;
        sf::RectangleShape BGFIN;
        sf::Texture fintexture;

        bool finishDrawed = false;

public:
        /**
         * Constructor with window
         * @param window
         */
        Background(const std::shared_ptr<sf::RenderWindow>& window, int type);

        /**
         * Draws the background
         */
        void draw() override;


};

} // namespace roadfighterSFML

#endif //ROADFIGHTER_BACKGROUND_H
