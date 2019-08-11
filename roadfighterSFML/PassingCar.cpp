//
// Created by senne on 12/21/18.
//

#include "PassingCar.h"
#include "../Singleton/Transformation.h"
#include "../Exception_class/SpriteLoadError.h"


void roadfighterSFML::PassingCar::draw() {
    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first, position.second);
    window->draw(sprite);
}

roadfighterSFML::PassingCar::PassingCar(const std::shared_ptr<sf::RenderWindow> window, double random,std::shared_ptr<ConfigData> config) : roadfighter::PassingCar(config) {
    this->window = window;
    centralpos = {random, 3.5};

    this->window = window;
    const char* file = config->getPassingCar().c_str();
    try {
        if (!texture.loadFromFile(file)) {
            throw (SpriteLoadError(file));
        }
    } catch (FileError &e) {
        std::cerr << e.what() << e.filePath()<<  std::endl;
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
