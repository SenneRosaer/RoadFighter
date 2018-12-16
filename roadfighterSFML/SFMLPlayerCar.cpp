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
    sprite.scale(1.3, 1.3);
}


void roadfighterSFML::PlayerCar::draw() {
    std::pair<float,float> position = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos);
    sprite.setPosition(position.first,position.second);
    window->draw(sprite);
}


void roadfighterSFML::PlayerCar::update() {

    std::vector<std::string> inputs;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        inputs.push_back("left");
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        inputs.push_back("right");
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        inputs.push_back("up");
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
        inputs.push_back("down");
    }

    UpdateMovement(inputs);
}
