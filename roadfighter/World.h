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

        bool rock = false;
        bool passingCar = false;
        bool movingCar = false;

    public:
        /**
         * Constructor
         */
        World(std::shared_ptr<ConfigData> config);

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
         * Updates the object with extra parameters
         * @param speed
         * @param Player
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Returns the speed of the object
         * @return speed
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
         * Returns a certain value to determine the delete status
         * 0 = nothing, 1 = delete, 2 = respawn
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


        /**
         * Add a rock to the rocks
         * @param rock
         */
        void addRock(std::shared_ptr<roadfighter::Entity> rock);

        /**
         * Return the movingcars
         * @return
         */
        const std::vector<std::shared_ptr<Entity>> &getMovingCars() const;

        /**
         * Add a moving car
         * @param car
         */
        void addMovingCar(std::shared_ptr<roadfighter::Entity> car);

        /**
         * Reset all the parameters to their starting value to start a new level or redo a level
         */
        void reset();

        /**
         * Return the current level
         * @return
         */
        int getCurrentLevel() const;

        /**
         * Set the current level
         * @param currentLevel
         */
        void setCurrentLevel(int currentLevel);

        /**
         * Finish the level
         * add final score of levels to total score and give signal for end of level
         */
        void finish();

        /**
         * Returns if the level is finished
         * @return
         */
        bool isLevelFinished() const;

        /**
         * Set if the level is finished
         * @param levelFinished
         */
        void setLevelFinished(bool levelFinished);

        /**
         * Get the reset timer for the world used at the end of a level
         * @return
         */
        int getWorldResetTimer() const;

        /**
         * Set the world reset timer
         * @param worldResetTimer
         */
        void setWorldResetTimer(int worldResetTimer);

        /**
         * Return if a level is started
         * (the beginnen of a level with the timer is not counted as started)
         * @return
         */
        bool isLevelStarted() const;

        /**
         * Set if the level is started
         */
        void setLevelStarted(bool levelStarted);

        /**
         * Return timer in frames (timer of 3 seconds for the start = 90 frames at 30FPS)
         * @return
         */
        int getTimerInFrames() const;

        /**
         * Set timer in frames
         * @param timerInFrames
         */
        void setTimerInFrames(int timerInFrames);

        /**
         * Set the AI
         * @param ai
         */
        void setAi(const std::shared_ptr<roadfighter::AIRacer> &ai);

        /**
         * Return the distance
         * @return
         */
        int getDistance() const;

        /**
         * Return if there is a boss fight happening
         * @return
         */
        bool isBossFight() const;

        /**
         * Return the boss
         * @return
         */
        const std::shared_ptr<roadfighter::Boss> &getBoss() const;

        /**
         * Set the boss
         * @param boss
         */
        void setBoss(const std::shared_ptr<roadfighter::Boss> &boss);

        /**
         * Initiate ending of game and set final scores
         */
        void gameEnd();

        /**
         * Return if game is ending
         * @return
         */
        bool isGameEnding() const;

        /**
         * Return distance to next level
         * @return
         */
        int getDistanceToNextLevel() const;

        /**
         * Return finalscores
         * @return
         */
        const std::vector<int> &getFinalscores() const;

        /**
         * Set the final scores
         * @param finalscores
         */
        void setFinalscores(const std::vector<int> &finalscores);

    };

} // namespace roadfighter

#endif // ROADFIGHTER_WORLD_H
