//
// Created by senne on 1/17/19.
//

#include "ObserverScore.h"
#include "../Singleton/Transformation.h"

ObserverScore::ObserverScore( std::shared_ptr<sf::RenderWindow> wind)

{
        this->window = wind;
        if (!font.loadFromFile("../Observer/arial.ttf")) {
                std::cout << "cant load font" << std::endl;
        }
        text.setFont(font);
        // text.setFillColor(sf::Color::White);
        text.setCharacterSize(30);
}

void ObserverScore::update(int score)
{
        text.setString("Score: " + std::to_string(score));
        std::pair<double, double> t =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({2, 0});
        text.setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
        window->draw(text);
}
