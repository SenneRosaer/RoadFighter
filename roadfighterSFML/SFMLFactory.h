//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_SFMLFACTORY_H
#define ROADFIGHTER_SFMLFACTORY_H

#include "../roadfighter/EntityFactory.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace roadfighterSFML {
class SFMLFactory : public roadfighter::EntityFactory{
    private:
        std::shared_ptr<sf::RenderWindow> window;
    public:
        SFMLFactory(std::shared_ptr<sf::RenderWindow> window);

        std::shared_ptr<roadfighter::Entity> createPlayerCar() override;

        std::shared_ptr<roadfighter::Entity> createBackground() override;

        std::shared_ptr<roadfighter::Entity> createPassingCar(double i) override;

    std::shared_ptr<roadfighter::Entity> createBullet(double first, double second) override;
};
}

#endif //ROADFIGHTER_SFMLFACTORY_H
