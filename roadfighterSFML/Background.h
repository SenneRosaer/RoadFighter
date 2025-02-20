//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_SFMLBACKGROUND_H
#define ROADFIGHTER_SFMLBACKGROUND_H

#include "../Observer/Observer.h"
#include "../roadfighter/Background.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace roadfighterSFML {
/**
 * Graphic side of the background
 */
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
         * Constructor with sfml level what the level is and configuration data
         * @param window
         * @param type
         * @param config
         */
        Background(const std::shared_ptr<sf::RenderWindow>& window, int type, std::shared_ptr<ConfigData> config);

        /**
         * Draws the background
         */
        void draw() override;
};

} // namespace roadfighterSFML

#endif // ROADFIGHTER_BACKGROUND_H
