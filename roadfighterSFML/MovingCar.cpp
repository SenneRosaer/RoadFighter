//
// Created by sennerosaer on 7/23/19.
//

#include "MovingCar.h"
#include "../Singleton/Transformation.h"
#include "../Exception_class/SpriteLoadError.h"

roadfighterSFML::MovingCar::MovingCar(const std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

roadfighterSFML::MovingCar::MovingCar(const std::shared_ptr<sf::RenderWindow> window, double random) {
    this->window = window;
    centralpos = {random, 3.5};

    this->window = window;

    try {
        if (!texture.loadFromFile("../Sprites/PassingCar2.piko")) {
            throw (SpriteLoadError("../Sprites/PassingCar2.piko"));
        }
    } catch (FileError &e) {
        std::cerr << e.what() <<e.filePath()<< std::endl;
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

void roadfighterSFML::MovingCar::draw() {
    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first, position.second);
    window->draw(sprite);
}
