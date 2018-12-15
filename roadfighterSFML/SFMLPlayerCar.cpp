//
// Created by senne on 12/15/18.
//

#include "SFMLPlayerCar.h"

roadfighterSFML::PlayerCar::PlayerCar(const std::shared_ptr<sf::RenderWindow> window){
    this->window = window;

    sf::Texture texture;
    texture.loadFromFile("../Sprites/CarPlayer.piko");
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.scale(1.2, 1.2);
}
