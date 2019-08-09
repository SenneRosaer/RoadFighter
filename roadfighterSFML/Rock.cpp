//
// Created by sennerosaer on 7/22/19.
//

#include "Rock.h"
#include "../Singleton/Transformation.h"

void roadfighterSFML::Rock::draw() {
    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first, position.second);
    window->draw(sprite);
}

roadfighterSFML::Rock::Rock(std::shared_ptr<sf::RenderWindow> window, double i) {
    this->window = window;
    centralpos = {i, 3.5};

    this->window = window;

    texture.loadFromFile("../Sprites/Rock.piko");
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.scale(1.3, 1.3);

    height = Transformation::getInstance(window->getSize().x, window->getSize().y)
            .heightReverse(sprite.getLocalBounds().height);
    width = Transformation::getInstance(window->getSize().x, window->getSize().y)
            .widthReverse(sprite.getLocalBounds().width);
}
