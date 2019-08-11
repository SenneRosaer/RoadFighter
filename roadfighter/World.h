//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include "../Observer/Subject.h"
#include "Entity.h"
#include "AIRacer.h"
#include "Boss.h"
#include <memory>
#include <vector>

class Observer;

namespace roadfighter {
    class World : public roadfighter::Entity, public Subject {

    private:
        std::shared_ptr<roadfighter::Entity> Player;


        std::shared_ptr<roadfighter::Entity> Background;

        std::vector<std::shared_ptr<roadfighter::Entity>> passingCars;

        std::vector<std::shared_ptr<roadfighter::Entity>> movingCars;


        std::vector<std::shared_ptr<roadfighter::Entity>> Bullets;

        std::vector<std::shared_ptr<roadfighter::Entity>> Rocks;

        std::shared_ptr<roadfighter::AIRacer> AI;

        bool shoot = false;

        // score
        int score = 0;

        int destroyedCars = 0;
        int crashes = 0;

        // Distance

        int Distance = 0;
        int DistanceToNextLevel = 100000;

        int speedAVG = 0;

        std::vector<std::shared_ptr<Observer>> observers;
        std::shared_ptr<Observer> StartRaceTimerObserver;

        int currentLevel;

        bool levelFinished = false;

        int worldResetTimer = 0;

        bool finisFunctionReached = false;

        //For timer at start of level
        bool levelStarted = false;
        int timerInFrames = 90;

        //Boss
        bool bossFight = false;

        std::shared_ptr<roadfighter::Boss> boss = nullptr;

        bool gameEnding = false;

        bool finishedFirst = false;

        std::vector<int> finalscores;

        bool crashDuringBoss = false;

    public:
        int respawnTimer = 30;

        //TODO getter setter
        bool rock = false;
        bool passingCar = false;
        bool movingCar = false;

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
        void setPlayer(const std::shared_ptr<Entity> &Player);

        /**
         * Set the background
         * @param Background
         */
        void setBackground(const std::shared_ptr<Entity> &Background);

        /**
         * Update an object
         */
        void update() override;

        /**
         * Update an object with a speed
         * @param speed
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Get the speed of an object
         * @return
         */
        int getSpeed() override;

        /**
         * Return the player
         * @return
         */
        const std::shared_ptr<Entity> &getPlayer() const;

        /**
         * Return the passingcars
         * @return
         */
        const std::vector<std::shared_ptr<Entity>> &getPassingCars() const;

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
        int Delete() override;

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
        void setDelete(int del) override;

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
        void notify() override;


        void addRock(std::shared_ptr<roadfighter::Entity> rock);

        const std::vector<std::shared_ptr<Entity>> &getMovingCars() const;

        void addMovingCar(std::shared_ptr<roadfighter::Entity> car);

        void reset();

        int getCurrentLevel() const;

        void setCurrentLevel(int currentLevel);

        void finish();

        bool isLevelFinished() const;

        void setLevelFinished(bool levelFinished);

        int getWorldResetTimer() const;

        void setWorldResetTimer(int worldResetTimer);

        bool isLevelStarted() const;

        void setLevelStarted(bool levelStarted);

        int getTimerInFrames() const;

        void setTimerInFrames(int timerInFrames);

        const std::shared_ptr<roadfighter::AIRacer> &getAi() const;

        void setAi(const std::shared_ptr<roadfighter::AIRacer> &ai);

        int getDistance() const;

        void setDistance(int distance);

        bool isBossFight() const;

        void setBossFight(bool bossFight);

        const std::shared_ptr<roadfighter::Boss> &getBoss() const;

        void setBoss(const std::shared_ptr<roadfighter::Boss> &boss);

        void gameEnd();

        bool isGameEnding() const;

        int getDistanceToNextLevel() const;

        const std::vector<int> &getFinalscores() const;

        void setFinalscores(const std::vector<int> &finalscores);

    };

} // namespace roadfighter

#endif // ROADFIGHTER_WORLD_H
