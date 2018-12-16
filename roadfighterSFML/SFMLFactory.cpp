//
// Created by senne on 12/15/18.
//

#include "SFMLFactory.h"
#include "SFMLPlayerCar.h"
#include "SFMLBackground.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPlayerCar() {
    return std::make_shared<roadfighterSFML::PlayerCar>(window);
}

roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBackground() {
    return std::make_shared<roadfighterSFML::SFMLBackground>(window);
}
