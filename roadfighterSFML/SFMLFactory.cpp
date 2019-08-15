//
// Created by senne on 12/15/18.
//

#include "SFMLFactory.h"
#include "AIRacer.h"
#include "Background.h"
#include "Boss.h"
#include "Bullet.h"
#include "MovingCar.h"
#include "PassingCar.h"
#include "PlayerCar.h"
#include "Rock.h"

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPlayerCar(int level)
{
        return std::make_shared<roadfighterSFML::PlayerCar>(window, level, Config);
}

roadfighterSFML::SFMLFactory::SFMLFactory(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<ConfigData> Config)
{
        this->window = window;
        this->Config = Config;
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBackground(int i)
{
        return std::make_shared<roadfighterSFML::Background>(window, i, Config);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createPassingCar(double i)
{
        return std::make_shared<roadfighterSFML::PassingCar>(window, i, Config);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createBullet(double first, double second)
{
        return std::make_shared<roadfighterSFML::Bullet>(window, first, second, Config);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createRock(double i)
{
        return std::make_shared<roadfighterSFML::Rock>(window, i, Config);
}

std::shared_ptr<roadfighter::Entity> roadfighterSFML::SFMLFactory::createMovingCar(double i)
{
        return std::make_shared<roadfighterSFML::MovingCar>(window, i, Config);
}

std::shared_ptr<roadfighter::AIRacer> roadfighterSFML::SFMLFactory::createAI()
{
        return std::make_shared<roadfighterSFML::AIRacer>(window, Config);
}

std::shared_ptr<roadfighter::Boss> roadfighterSFML::SFMLFactory::createBoss()
{
        return std::make_shared<roadfighterSFML::Boss>(window, Config);
}
