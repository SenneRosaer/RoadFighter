//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_SFMLFACTORY_H
#define ROADFIGHTER_SFMLFACTORY_H

#include "../roadfighter/EntityFactory.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace roadfighterSFML {
    class SFMLFactory : public roadfighter::EntityFactory {
    private:
        std::shared_ptr<sf::RenderWindow> window;

    public:
        /**
         * Constructor with window
         * @param window
         */
        SFMLFactory(std::shared_ptr<sf::RenderWindow> window);

        /**
         * Create a playercar
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Entity> createPlayerCar(int level) override;

        /**
         * Create a background
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Entity> createBackground(int i) override;

        /**
         * Create a passing car
         * @param i = random value to spawn
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Entity> createPassingCar(double i) override;

        /**
         * Create a Bullet with to doubles for the location of the car
         * @param first = x location
         * @param second  = y location
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Entity> createBullet(double first, double second) override;

        std::shared_ptr<roadfighter::Entity> createRock(double i) override;

        std::shared_ptr<roadfighter::Entity> createMovingCar(double i) override;

        std::shared_ptr<roadfighter::AIRacer> createAI() override;


    };
} // namespace roadfighterSFML

#endif // ROADFIGHTER_SFMLFACTORY_H
