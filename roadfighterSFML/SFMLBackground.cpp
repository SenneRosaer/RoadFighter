//
// Created by senne on 12/16/18.
//

#include "SFMLBackground.h"

roadfighterSFML::SFMLBackground::SFMLBackground(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    texture.loadFromFile("../Sprites/road.png");

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void roadfighterSFML::SFMLBackground::draw() {

}

void roadfighterSFML::SFMLBackground::update() {

}
