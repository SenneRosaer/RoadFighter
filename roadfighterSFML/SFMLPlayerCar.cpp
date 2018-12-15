//
// Created by senne on 12/15/18.
//

#include "SFMLPlayerCar.h"
#include "../Singleton/Transformation.h"

roadfighterSFML::PlayerCar::PlayerCar(const std::shared_ptr<sf::RenderWindow> window){
    this->window = window;

    texture.loadFromFile("../Sprites/CarPlayer.piko");
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.scale(1.2, 1.2);
}


void roadfighterSFML::PlayerCar::draw() {
    std::pair<float,float> position = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first,position.second);
    window->draw(sprite);
}
