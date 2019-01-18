//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include "../Observer/Subject.h"
#include "Entity.h"
#include <memory>
#include <vector>
class Observer;

namespace roadfighter {
class World : public roadfighter::Entity, public Subject
{

private:
        std::shared_ptr<roadfighter::Entity> Player;

        std::shared_ptr<roadfighter::Entity> Background;

        std::vector<std::shared_ptr<roadfighter::Entity>> passingCars;

        std::vector<std::shared_ptr<roadfighter::Entity>> Bullets;

        bool shoot = false;

        // score
        int score = 0;

        int destroyedCars = 0;
        int crashes = 0;

        // Distance
        int SpeedLoop = 10;

        int Distance = 0;

        int speedAVG = 0;

        std::vector<std::shared_ptr<Observer>> observers;

public:
        int respawnTimer = 30;

public:
        /**
         * Constructor
         */
        World();

        /**
         * Draw all the objects in the world
         */
        void draw() override;

        /**
         * Set the player
         * @param Player
         */
        void setPlayer(const std::shared_ptr<Entity>& Player);

        /**
         * Set the background
         * @param Background
         */
        void setBackground(const std::shared_ptr<Entity>& Background);

        /**
         * Update an object
         */
        void update() override;

        /**
         * Update an object with a speed
         * @param speed
         */
        void update(int speed) override;

        /**
         * Get the speed of an object
         * @return
         */
        int getSpeed() override;

        /**
         * Return the player
         * @return
         */
        const std::shared_ptr<Entity>& getPlayer() const;

        /**
         * Return the passingcars
         * @return
         */
        const std::vector<std::shared_ptr<Entity>>& getPassingCars() const;

        /**
         * Add a passingcar
         * @param car
         */
        void addPassingCar(std::shared_ptr<roadfighter::Entity> car);

        /**
         * Add a bullet
         * @param bullet
         */
        void addBullet(std::shared_ptr<roadfighter::Entity> bullet);

        /**
         * Return if we have to delete the object
         * @return
         */
        bool Delete() override;

        /**
         * Control collision between player and other cars and between other cars and bullets
         */
        void Collision();

        /**
         * Get the object box with size parameters
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Set to delete the object
         * @param del
         */
        void setDelete(bool del) override;

        /**
         *
         * @return
         */
        bool Shoot() override;

        /**
         * Control if the player shot
         * @return
         */
        bool isShoot() const;

        /**
         * Calculate the distance
         */
        void calcDistance();

        /**
         * Calculate the score
         */
        void calcScore();

        /**
         * Attach an observer to the observers
         * @param observer
         */
        void attach(std::shared_ptr<Observer> observer) override;

        /**
         * Notify the observers
         * @param scoreUpdate
         */
        void notify(int scoreUpdate) override;
};

} // namespace roadfighter

#endif // ROADFIGHTER_WORLD_H
