//
// Created by sennerosaer on 8/7/19.
//

#include "AIRacer.h"
#include "../Singleton/Transformation.h"
#include "../Exception_class/SpriteLoadError.h"

roadfighterSFML::AIRacer::AIRacer(const std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
    try {
        if (!texture.loadFromFile("../Sprites/AIRacer.piko")) {
            throw (SpriteLoadError());
        }
    } catch(GameError& e){
        std::cerr << e.what() << std::endl;
        throw;
    }
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.scale(1.3, 1.3);

    height = Transformation::getInstance(window->getSize().x, window->getSize().y).heightReverse(texture.getSize().y);
    width = Transformation::getInstance(window->getSize().x, window->getSize().y).widthReverse(texture.getSize().x);
}

void roadfighterSFML::AIRacer::draw() {
    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first, position.second);
    window->draw(sprite);
}

void roadfighterSFML::AIRacer::update() {

}
