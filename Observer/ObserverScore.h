//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_OBSERVERSCORE_H
#define ROADFIGHTER_OBSERVERSCORE_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

class ObserverScore : public Observer
{
private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Font font;
        sf::Text text;

public:
        ObserverScore(std::shared_ptr<sf::RenderWindow> wind);

        void update(int score) override;
};

#endif // ROADFIGHTER_OBSERVERSCORE_H
