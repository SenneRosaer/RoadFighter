//
// Created by sennerosaer on 8/7/19.
//

#ifndef ROADFIGHTER_SFMLAIRACER_H
#define ROADFIGHTER_SFMLAIRACER_H

#include "../roadfighter/AIRacer.h"
#include "SFML/Graphics.hpp"

namespace roadfighterSFML {
    class AIRacer : public roadfighter::AIRacer {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
       /**
        * Constructor with sfml window and configuration data
        * @param window
        * @param config
        */
        AIRacer(const std::shared_ptr<sf::RenderWindow> window,std::shared_ptr<ConfigData> config);
        /**
         * Draws the player
         */
        void draw() override;

        /**
         * Updates the player
         */
        void update() override;
    };
}

#endif //ROADFIGHTER_AIRACER_H
