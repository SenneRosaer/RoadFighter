//
// Created by senne on 12/15/18.
//

#include "SFMLFactory.h"
#include "SFMLBackground.h"
#include "SFMLBullet.h"
#include "SFMLPassingCar.h"
#include "SFMLPlayerCar.h"
#include "SFMLRock.h"
#include "SFMLMovingCar.h"
#include "SFMLAIRacer.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPlayerCar(int level)
{
        return std::make_shared<roadfighterSFML::PlayerCar>(window,level);
}

roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window) { this->window = window; }

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBackground(int i)
{
        return std::make_shared<roadfighterSFML::SFMLBackground>(window, i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPassingCar(double i)
{
        return std::make_shared<roadfighterSFML::PassingCar>(window, i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBullet(double first, double second)
{
        return std::make_shared<roadfighterSFML::SFMLBullet>(window, first, second);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createRock(double i) {
        return std::make_shared<roadfighterSFML::SFMLRock>(window,i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createMovingCar(double i) {
        return std::make_shared<roadfighterSFML::SFMLMovingCar>(window,i);
}

std::shared_ptr<roadfighter::AIRacer> roadfighterSFML::SFMLFactory::createAI() {
    return std::make_shared<roadfighterSFML::SFMLAIRacer>(window);
}
