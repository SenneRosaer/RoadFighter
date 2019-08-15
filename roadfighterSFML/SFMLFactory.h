//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_SFMLFACTORY_H
#define ROADFIGHTER_SFMLFACTORY_H

#include "../roadfighter/EntityFactory.h"
#include "../roadfighter/Boss.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace roadfighterSFML {
    /**
     * SFML side of the factory that makes sure every object can acces the window
     */
    class SFMLFactory : public roadfighter::EntityFactory {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<ConfigData> Config;

    public:
        /**
         * Constructor of factory with sfml window and configuration data
         * @param window
         * @param Config
         */
        SFMLFactory(std::shared_ptr<sf::RenderWindow> window,std::shared_ptr<ConfigData> Config);

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

        /**
         * Create a Rock with a random position
         * @param i
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Entity> createRock(double i) override;

        /**
         * Create a moving car with a random position
         * @param i
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Entity> createMovingCar(double i) override;

        /**
         * Create an ai
         * @return shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::AIRacer> createAI() override;

        /**
         * Create a boss
         * @return  shared_ptr of Entity
         */
        std::shared_ptr<roadfighter::Boss> createBoss() override;


    };
} // namespace roadfighterSFML

#endif // ROADFIGHTER_SFMLFACTORY_H
