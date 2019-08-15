//
// Created by senne on 12/15/18.
//

#include "World.h"
#include "../Exception_class/GameError.h"
#include "../Exception_class/ScoreError.h"
#include "../Observer/Observer.h"
#include "EntityFactory.h"
#include <iostream>

void roadfighter::World::draw()
{
        // Draws all the objects that need to be
        Background->draw();
        if (Player != nullptr and Player->Delete() != 2) {
                Player->draw();
        }
        for (auto passingcar : passingCars) {
                passingcar->draw();
        }
        for (auto movingcar : movingCars) {
                movingcar->draw();
        }
        for (auto bullet : Bullets) {
                bullet->draw();
        }
        for (auto rock : Rocks) {
                rock->draw();
        }

        if (AI != nullptr and AI->Delete() != 2) {
                AI->draw();
        }
        if (boss != nullptr) {
                boss->draw();
        }
}

roadfighter::World::World(std::shared_ptr<ConfigData> config) { roadfighter::Entity::Config = config; }

void roadfighter::World::setPlayer(const std::shared_ptr<roadfighter::Entity>& Player) { World::Player = Player; }

void roadfighter::World::update()
{
        // deletes
        if (passingCars.size() != 0) {
                for (int i = passingCars.size() - 1; i >= 0; i--) {
                        if (passingCars[i]->Delete() == 1) {
                                passingCars.erase(passingCars.begin() + i);
                        }
                }
        }

        if (movingCars.size() != 0) {
                for (int i = movingCars.size() - 1; i >= 0; i--) {
                        if (movingCars[i]->Delete() == 1) {
                                movingCars.erase(movingCars.begin() + i);
                        }
                }
        }

        if (Bullets.size() != 0) {
                for (int i = Bullets.size() - 1; i >= 0; i--) {
                        if (Bullets[i]->Delete() == 1) {
                                Bullets.erase(Bullets.begin() + i);
                        }
                }
        }
        if (Rocks.size() != 0) {
                for (int i = Rocks.size() - 1; i >= 0; i--) {
                        if (Rocks[i]->Delete() == 1) {
                                Rocks.erase(Rocks.begin() + i);
                        }
                }
        }
        // control for collision
        Collision();

        // Update background with player speed or shoots and updates
        if (Player == nullptr) {
                shoot = false;
                Background->update(0, Player);

        } else {
                shoot = Player->Shoot();
                Player->update();
                Background->update(Player->getSpeed(), Player);
        }

        // updates all the bullets
        for (auto bullet : Bullets) {
                if (Player == nullptr) {
                        bullet->update(0, Player);
                } else {
                        bullet->update(Player->getSpeed(), Player);
                }
        }

        // Updates the passingcars
        for (auto passingcar : passingCars) {
                if (Player == nullptr) {
                        passingcar->update(0, Player);
                } else {
                        passingcar->update(Player->getSpeed(), Player);
                }
        }

        // updates the movingcars
        for (auto movingcar : movingCars) {
                if (Player == nullptr) {
                        movingcar->update(0, Player);
                } else {
                        movingcar->update(Player->getSpeed(), Player);
                }
        }

        // updates the rocks
        for (auto rock : Rocks) {
                if (Player == nullptr) {
                        rock->update(0, Player);
                } else {
                        rock->update(Player->getSpeed(), Player);
                }
        }

        // control if whe need to delete certain objects
        if (Player != nullptr) {
                calcDistance();
                if (getPlayer()->Delete() == 1) {
                        setPlayer(nullptr);
                }
        }

        if (AI != nullptr) {
                AI->updateMovement(passingCars, movingCars, Rocks, Player);
                if (AI->Delete() == 1) {
                        setAi(nullptr);
                }
        }

        if (boss != nullptr and Player != nullptr) {
                boss->update();
                if (boss->Delete() == 1) {
                        setBoss(nullptr);
                }
                if (AI != nullptr) {
                        if (AI->getObjbox()->centralpos.second < -3 or AI->getObjbox()->centralpos.second > 3) {
                                AI = nullptr;
                        }
                }
        }

        // Distance to next level cannot be negative
        if (Player != nullptr) {
                DistanceToNextLevel = DistanceToNextLevel - Player->getSpeed();
                if (DistanceToNextLevel < 0) {
                        DistanceToNextLevel = 0;
                }
        }
        // See who finished first
        if (AI != nullptr and Player != nullptr) {
                if (AI->getCarTravelledDistance() <= 100000 and getDistance() >= 100000) {
                        finishedFirst = true;
                }
        }

        // bossfight or finish level
        if (Distance > 100000 and currentLevel != 3) {
                finish();
        } else if (Distance >= 100000 and currentLevel == 3) {
                bossFight = true;
        }

        calcScore();
        notify();
}

void roadfighter::World::setBackground(const std::shared_ptr<roadfighter::Entity>& Background)
{
        World::Background = Background;
}

void roadfighter::World::update(int speed, std::shared_ptr<roadfighter::Entity> Player) {}

int roadfighter::World::getSpeed() { return 0; }

const std::shared_ptr<roadfighter::Entity>& roadfighter::World::getPlayer() const { return Player; }

const std::vector<std::shared_ptr<roadfighter::Entity>>& roadfighter::World::getPassingCars() const
{
        return passingCars;
}

void roadfighter::World::addPassingCar(std::shared_ptr<roadfighter::Entity> car) { passingCars.push_back(car); }

int roadfighter::World::Delete() { return 0; }

void roadfighter::World::Collision()
{
        // TODO FIX
        std::vector<std::shared_ptr<roadfighter::Entity>> allPlayerCollisionObj;
        for (auto item : Rocks) {
                allPlayerCollisionObj.push_back(item);
        }
        for (auto item : passingCars) {
                allPlayerCollisionObj.push_back(item);
        }
        for (auto item : movingCars) {
                allPlayerCollisionObj.push_back(item);
        }

        // control collision of player with other objects
        if (getPlayer() != nullptr and Player->Delete() != 2) {
                std::shared_ptr<ObjBox> PlayerBox = Player->getObjbox();
                double width1 = PlayerBox->centralpos.first - PlayerBox->width / 2;
                double width2 = PlayerBox->centralpos.first + PlayerBox->width / 2;
                double heigth1 = PlayerBox->centralpos.second - PlayerBox->height / 2;
                double heigth2 = PlayerBox->centralpos.second + PlayerBox->height / 2;
                for (auto collisionObj : allPlayerCollisionObj) {
                        // Left upper left lower right upper ...
                        std::shared_ptr<ObjBox> carBox = collisionObj->getObjbox();
                        std::pair<double, double> LUCorner = {carBox->centralpos.first - carBox->width / 2,
                                                              carBox->centralpos.second + carBox->height / 2};
                        std::pair<double, double> RUCorner = {carBox->centralpos.first + carBox->width / 2,
                                                              carBox->centralpos.second + carBox->height / 2};
                        std::pair<double, double> LLCorner = {carBox->centralpos.first - carBox->width / 2,
                                                              carBox->centralpos.second - carBox->height / 2};
                        std::pair<double, double> RLCorner = {carBox->centralpos.first + carBox->width / 2,
                                                              carBox->centralpos.second - carBox->height / 2};
                        std::vector<std::pair<double, double>> tempvec = {LUCorner, RUCorner, LLCorner, RLCorner};
                        for (int i = 0; i < 4; i++) {
                                if (tempvec[i].first >= width1 and tempvec[i].first <= width2) {
                                        if (tempvec[i].second <= heigth2 and tempvec[i].second >= heigth1) {
                                                // respawn player and delete other object
                                                getPlayer()->setDelete(2);
                                                collisionObj->setDelete(1);
                                                crashes++;
                                                calcScore();
                                                // Make sure you can also crash and lose points during bossfight
                                                if (bossFight) {
                                                        crashDuringBoss = true;
                                                }
                                                notify();
                                                break;
                                        }
                                }
                        }
                }
        }
        // Control collision for ai
        if (AI != nullptr and AI->Delete() != 2) {
                auto allAICollisionObj = allPlayerCollisionObj;
                allAICollisionObj.insert(allAICollisionObj.end(), Bullets.begin(), Bullets.end());
                std::shared_ptr<ObjBox> PlayerBox = AI->getObjbox();
                double width1 = PlayerBox->centralpos.first - PlayerBox->width / 2;
                double width2 = PlayerBox->centralpos.first + PlayerBox->width / 2;
                double heigth1 = PlayerBox->centralpos.second - PlayerBox->height / 2;
                double heigth2 = PlayerBox->centralpos.second + PlayerBox->height / 2;
                for (auto collisionObj : allAICollisionObj) {
                        // Left upper left lower right upper ...
                        std::shared_ptr<ObjBox> carBox = collisionObj->getObjbox();
                        std::pair<double, double> LUCorner = {carBox->centralpos.first - carBox->width / 2,
                                                              carBox->centralpos.second + carBox->height / 2};
                        std::pair<double, double> RUCorner = {carBox->centralpos.first + carBox->width / 2,
                                                              carBox->centralpos.second + carBox->height / 2};
                        std::pair<double, double> LLCorner = {carBox->centralpos.first - carBox->width / 2,
                                                              carBox->centralpos.second - carBox->height / 2};
                        std::pair<double, double> RLCorner = {carBox->centralpos.first + carBox->width / 2,
                                                              carBox->centralpos.second - carBox->height / 2};
                        std::vector<std::pair<double, double>> tempvec = {LUCorner, RUCorner, LLCorner, RLCorner};
                        for (int i = 0; i < 4; i++) {
                                if (tempvec[i].first >= width1 and tempvec[i].first <= width2) {
                                        if (tempvec[i].second <= heigth2 and tempvec[i].second >= heigth1) {
                                                AI->setDelete(2);
                                                collisionObj->setDelete(1);
                                                break;
                                        }
                                }
                        }
                }
                // if there is collision between ai and player both need to be respawned
                if (Player->Delete() != 2) {
                        std::shared_ptr<ObjBox> carBox = Player->getObjbox();
                        std::pair<double, double> LUCorner = {carBox->centralpos.first - carBox->width / 2,
                                                              carBox->centralpos.second + carBox->height / 2};
                        std::pair<double, double> RUCorner = {carBox->centralpos.first + carBox->width / 2,
                                                              carBox->centralpos.second + carBox->height / 2};
                        std::pair<double, double> LLCorner = {carBox->centralpos.first - carBox->width / 2,
                                                              carBox->centralpos.second - carBox->height / 2};
                        std::pair<double, double> RLCorner = {carBox->centralpos.first + carBox->width / 2,
                                                              carBox->centralpos.second - carBox->height / 2};
                        std::vector<std::pair<double, double>> tempvec = {LUCorner, RUCorner, LLCorner, RLCorner};
                        for (int i = 0; i < 4; i++) {
                                if (tempvec[i].first >= width1 and tempvec[i].first <= width2) {
                                        if (tempvec[i].second <= heigth2 and tempvec[i].second >= heigth1) {
                                                AI->setDelete(2);
                                                Player->setDelete(2);
                                                break;
                                        }
                                }
                        }
                }
        }

        std::vector<std::shared_ptr<roadfighter::Entity>> allCarCollisionObj;
        for (auto item : passingCars) {
                allCarCollisionObj.push_back(item);
        }
        for (auto item : movingCars) {
                allCarCollisionObj.push_back(item);
        }

        // Control collision between objects and bullets
        for (auto passingcar : allCarCollisionObj) {
                std::shared_ptr<ObjBox> PassingBox = passingcar->getObjbox();

                double Width1 = PassingBox->centralpos.first - PassingBox->width / 2;
                double Width2 = PassingBox->centralpos.first + PassingBox->width / 2;
                double Heigth1 = PassingBox->centralpos.second - PassingBox->height / 2;
                double Heigth2 = PassingBox->centralpos.second + PassingBox->height / 2;

                for (auto bullet : Bullets) {
                        std::pair<double, double> Position = bullet->getObjbox()->centralpos;

                        if (Position.first >= Width1 - 0.05 and Position.first <= Width2) {
                                if (Position.second >= Heigth1 and Position.second <= Heigth2) {
                                        bullet->setDelete(1);
                                        passingcar->setDelete(1);
                                        // update score if necessary
                                        destroyedCars++;
                                        calcScore();
                                        notify();
                                }
                        }
                }
                for (auto rock : Rocks) {
                        std::pair<double, double> Position = rock->getObjbox()->centralpos;

                        if (Position.first >= Width1 - 0.05 and Position.first <= Width2 + 0.05) {
                                if (Position.second >= Heigth1 and Position.second <= Heigth2 + 0.1) {
                                        rock->setDelete(1);
                                        passingcar->setDelete(1);
                                }
                        }
                }
                for (auto passingCars2 : allCarCollisionObj) {

                        std::shared_ptr<ObjBox> carBox = passingCars2->getObjbox();
                        if (carBox->centralpos.first != PassingBox->centralpos.first and
                            carBox->centralpos.second != PassingBox->centralpos.second) {
                                std::pair<double, double> LUCorner = {carBox->centralpos.first - carBox->width / 2,
                                                                      carBox->centralpos.second + carBox->height / 2};
                                std::pair<double, double> RUCorner = {carBox->centralpos.first + carBox->width / 2,
                                                                      carBox->centralpos.second + carBox->height / 2};
                                std::pair<double, double> LLCorner = {carBox->centralpos.first - carBox->width / 2,
                                                                      carBox->centralpos.second - carBox->height / 2};
                                std::pair<double, double> RLCorner = {carBox->centralpos.first + carBox->width / 2,
                                                                      carBox->centralpos.second - carBox->height / 2};
                                std::vector<std::pair<double, double>> tempvec = {LUCorner, RUCorner, LLCorner,
                                                                                  RLCorner};
                                for (int i = 0; i < 4; i++) {
                                        if (tempvec[i].first >= Width1 and tempvec[i].first <= Width2) {
                                                if (tempvec[i].second <= Heigth2 and tempvec[i].second >= Heigth1) {
                                                        passingcar->setDelete(1);
                                                        passingCars2->setDelete(1);
                                                        break;
                                                }
                                        }
                                }
                        }
                }
        }

        // Control collision with boss so we know when we hit him and change his lifes
        if (boss != nullptr) {
                std::shared_ptr<ObjBox> PassingBox = boss->getObjbox();

                double Width1 = PassingBox->centralpos.first - PassingBox->width / 2;
                double Width2 = PassingBox->centralpos.first + PassingBox->width / 2;
                double Heigth1 = PassingBox->centralpos.second - PassingBox->height / 2;
                double Heigth2 = PassingBox->centralpos.second + PassingBox->height / 2;

                for (auto bullet : Bullets) {
                        std::pair<double, double> Position = bullet->getObjbox()->centralpos;

                        if (Position.first >= Width1 - 0.05 and Position.first <= Width2 + 0.05) {
                                if (Position.second >= Heigth1 and Position.second <= Heigth2) {
                                        bullet->setDelete(1);
                                        if (boss->getLife() > 0) {
                                                boss->setLife(boss->getLife() - 1);
                                        }
                                        if (boss->getLife() == 0) {
                                                boss->setDelete(1);
                                                gameEnd();
                                        }
                                }
                        }
                }
        }
}

std::shared_ptr<ObjBox> roadfighter::World::getObjbox() { return std::shared_ptr<ObjBox>(); }

void roadfighter::World::setDelete(int del) {}

bool roadfighter::World::Shoot() { return false; }

bool roadfighter::World::isShoot() const { return shoot; }

void roadfighter::World::addBullet(std::shared_ptr<roadfighter::Entity> bullet) { Bullets.push_back(bullet); }

void roadfighter::World::calcDistance()
{
        // calculate distance based on speed
        Distance = Distance + Player->getSpeed();
        if (DistanceToNextLevel == 0) {
                Distance = roadfighter::Entity::Config->getDistance();
        }
}

void roadfighter::World::calcScore()
{
        // calculate scores based on finishorder, crashes ,distance , destroyed cars
        try {
                if (!bossFight) {
                        if (!levelFinished) {
                                if (DistanceToNextLevel == 0) {
                                        Distance = roadfighter::Entity::Config->getDistance();
                                }
                                int dist = (Distance / 100);
                                int destr = destroyedCars * 50;
                                int crash = crashes * -100;
                                score = dist + destr + crash;

                                if (finishedFirst) {
                                        score = score + 500;
                                }
                        }
                } else {
                        if (crashDuringBoss) {
                                score = score - 100;
                                crashDuringBoss = false;
                        }
                }
                if (score < 0) {
                        throw(ScoreError());
                }
        } catch (GameError& e) {
                std::cerr << e.what() << std::endl;
                score = 0;
        }
}

void roadfighter::World::attach(std::shared_ptr<Observer> observer) { observers.push_back(observer); }

void roadfighter::World::notify()
{
        // Notify the observer for score or for the startracetimer
        for (auto obs : observers) {
                if (obs->getType() == "Score") {
                        obs->update(score);
                } else if (obs->getType() == "StartRaceTimer" and !levelStarted) {
                        int timer;
                        if (timerInFrames <= 90 and timerInFrames > 60) {
                                timer = 3;
                        }
                        if (timerInFrames <= 60 and timerInFrames > 30) {
                                timer = 2;
                        }
                        if (timerInFrames <= 30 and timerInFrames > 0) {
                                timer = 1;
                        }
                        if (timerInFrames <= 0) {
                                timer = 0;
                        }
                        obs->update(timer);
                }
        }
}

void roadfighter::World::addRock(std::shared_ptr<roadfighter::Entity> rock) { Rocks.push_back(rock); }

const std::vector<std::shared_ptr<roadfighter::Entity>>& roadfighter::World::getMovingCars() const
{
        return movingCars;
}

void roadfighter::World::addMovingCar(std::shared_ptr<roadfighter::Entity> car) { movingCars.push_back(car); }

void roadfighter::World::reset()
{
        // Reset all the parameters to the beginning
        score = 0;
        destroyedCars = 0;
        crashes = 0;
        Distance = 0;
        DistanceToNextLevel = roadfighter::Entity::Config->getDistance();
        finalscores = {};

        Player.reset();
        Background.reset();
        passingCars.clear();
        movingCars.clear();
        Bullets.clear();
        Rocks.clear();
        AI.reset();
        boss.reset();

        rock = false;
        passingCar = false;
        movingCar = false;
        finisFunctionReached = false;
        levelStarted = false;
        bossFight = false;
        timerInFrames = 90;
        gameEnding = false;
        boss = nullptr;
        finishedFirst = false;
}

int roadfighter::World::getCurrentLevel() const { return currentLevel; }

void roadfighter::World::setCurrentLevel(int currentLevel) { World::currentLevel = currentLevel; }

void roadfighter::World::finish()
{
        if (!finisFunctionReached) {
                calcScore();
                notify();
                levelFinished = true;

                worldResetTimer = 60;

                finisFunctionReached = true;
                finalscores.push_back(score);
        }
}

bool roadfighter::World::isLevelFinished() const { return levelFinished; }

void roadfighter::World::setLevelFinished(bool levelFinished) { World::levelFinished = levelFinished; }

int roadfighter::World::getWorldResetTimer() const { return worldResetTimer; }

void roadfighter::World::setWorldResetTimer(int worldResetTimer) { World::worldResetTimer = worldResetTimer; }

bool roadfighter::World::isLevelStarted() const { return levelStarted; }

void roadfighter::World::setLevelStarted(bool levelStarted) { World::levelStarted = levelStarted; }

int roadfighter::World::getTimerInFrames() const { return timerInFrames; }

void roadfighter::World::setTimerInFrames(int timerInFrames) { World::timerInFrames = timerInFrames; }

void roadfighter::World::setAi(const std::shared_ptr<roadfighter::AIRacer>& ai) { AI = ai; }

int roadfighter::World::getDistance() const { return Distance; }

bool roadfighter::World::isBossFight() const { return bossFight; }

const std::shared_ptr<roadfighter::Boss>& roadfighter::World::getBoss() const { return boss; }

void roadfighter::World::setBoss(const std::shared_ptr<roadfighter::Boss>& boss) { World::boss = boss; }

void roadfighter::World::gameEnd()
{
        // Player = nullptr;
        gameEnding = true;
        finalscores.push_back(score);
}

bool roadfighter::World::isGameEnding() const { return gameEnding; }

int roadfighter::World::getDistanceToNextLevel() const { return DistanceToNextLevel; }

const std::vector<int>& roadfighter::World::getFinalscores() const { return finalscores; }

void roadfighter::World::setFinalscores(const std::vector<int>& finalscores) { World::finalscores = finalscores; }
