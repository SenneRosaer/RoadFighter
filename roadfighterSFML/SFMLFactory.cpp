//
// Created by senne on 12/15/18.
//

#include "SFMLFactory.h"
#include "Background.h"
#include "Bullet.h"
#include "PassingCar.h"
#include "PlayerCar.h"
#include "Rock.h"
#include "MovingCar.h"
#include "AIRacer.h"
#include "Boss.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPlayerCar(int level)
{
        return std::make_shared<roadfighterSFML::PlayerCar>(window,level);
}

roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window) { this->window = window; }

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBackground(int i)
{
        return std::make_shared<roadfighterSFML::Background>(window, i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPassingCar(double i)
{
        return std::make_shared<roadfighterSFML::PassingCar>(window, i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBullet(double first, double second)
{
        return std::make_shared<roadfighterSFML::Bullet>(window, first, second);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createRock(double i) {
        return std::make_shared<roadfighterSFML::Rock>(window, i);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createMovingCar(double i) {
        return std::make_shared<roadfighterSFML::MovingCar>(window, i);
}

std::shared_ptr<roadfighter::AIRacer> roadfighterSFML::SFMLFactory::createAI() {
    return std::make_shared<roadfighterSFML::AIRacer>(window);
}

std::shared_ptr<roadfighter::Boss> roadfighterSFML::SFMLFactory::createBoss() {
    return std::make_shared<roadfighterSFML::Boss>(window);
}
