//
// Created by senne on 12/15/18.
//

#include "SFMLFactory.h"
#include "SFMLBackground.h"
#include "SFMLBullet.h"
#include "SFMLPassingCar.h"
#include "SFMLPlayerCar.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPlayerCar()
{
        return std::make_shared<roadfighterSFML::PlayerCar>(window);
}

roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window) { this->window = window; }

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBackground()
{
        return std::make_shared<roadfighterSFML::SFMLBackground>(window);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPassingCar(double i)
{
        return std::make_shared<roadfighterSFML::PassingCar>(window, i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBullet(double first, double second)
{
        return std::make_shared<roadfighterSFML::SFMLBullet>(window, first, second);
}
