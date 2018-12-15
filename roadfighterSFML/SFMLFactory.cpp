//
// Created by senne on 12/15/18.
//

#include "SFMLFactory.h"
#include "SFMLPlayerCar.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPlayerCar() {
    return std::make_shared<roadfighterSFML::PlayerCar>(window);
}

roadfighterSFML::SFMLFactory::SFMLFactory() {
    window.get()->create(sf::VideoMode(300,400),"RoadFighter");
}
