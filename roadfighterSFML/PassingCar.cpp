//
// Created by senne on 12/21/18.
//

#include "PassingCar.h"
#include "../Singleton/Transformation.h"
#include "../Exception_class/SpriteLoadError.h"

roadfighterSFML::PassingCar::PassingCar(const std::shared_ptr<sf::RenderWindow> window) { this->window = window; }

void roadfighterSFML::PassingCar::draw() {
    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first, position.second);
    window->draw(sprite);
}

roadfighterSFML::PassingCar::PassingCar(const std::shared_ptr<sf::RenderWindow> window, double random) {
    this->window = window;
    centralpos = {random, 3.5};

    this->window = window;

    try {
        if (!texture.loadFromFile("../Sprites/PassingCar1.piko")) {
            throw (SpriteLoadError());
        }
    } catch (GameError &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.scale(1.3, 1.3);

    height = Transformation::getInstance(window->getSize().x, window->getSize().y)
            .heightReverse(sprite.getLocalBounds().height);
    width = Transformation::getInstance(window->getSize().x, window->getSize().y)
            .widthReverse(sprite.getLocalBounds().width);

}
