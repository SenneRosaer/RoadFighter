//
// Created by senne on 12/21/18.
//

#include "SFMLPassingCar.h"
#include "../Singleton/Transformation.h"

roadfighterSFML::PassingCar::PassingCar(const std::shared_ptr<sf::RenderWindow> window) { this->window = window; }

void roadfighterSFML::PassingCar::draw()
{
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

roadfighterSFML::PassingCar::PassingCar(const std::shared_ptr<sf::RenderWindow> window, double random)
{
        this->window = window;
        centralpos = {random, 3.5};

        this->window = window;

        texture.loadFromFile("../Sprites/PassingCar1.piko");
        texture.setSmooth(true);

        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.scale(1.3, 1.3);

        height = Transformation::getInstance(window->getSize().x, window->getSize().y)
                     .heightReverse(texture.getSize().y * 0.5);
        width = Transformation::getInstance(window->getSize().x, window->getSize().y)
                    .widthReverse(texture.getSize().x * 0.5);

}
