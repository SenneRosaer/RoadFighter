//
// Created by senne on 12/15/18.
//

#include "World.h"
#include "EntityFactory.h"
#include <iostream>
#include "../Observer/Observer.h"

void roadfighter::World::draw() {
    Background->draw();
    if(Player != nullptr) {
        Player->draw();
    }
    for(auto passingcar : passingCars){
        passingcar->draw();
    }
    for(auto bullet: Bullets){
        bullet->draw();
    }
}

roadfighter::World::World() {
}

void roadfighter::World::setPlayer(const std::shared_ptr<roadfighter::Entity> &Player) {
    World::Player = Player;
}

void roadfighter::World::update(){
    //deletes
    if(passingCars.size() != 0) {
        for (int i = passingCars.size() - 1; i >= 0; i--) {
            if (passingCars[i]->Delete()) {
                passingCars.erase(passingCars.begin() + i);
            }
        }
    }

    if(Bullets.size() != 0) {
        for (int i = Bullets.size() - 1; i >= 0; i--) {
            if (Bullets[i]->Delete()) {
                Bullets.erase(Bullets.begin() + i);
            }
        }
    }

    if(Player == nullptr) {
        shoot = false;
        Background->update(0);


    } else {
        shoot = Player->Shoot();
        Player->update();
        Background->update(Player->getSpeed());

    }


    for(auto bullet: Bullets){
        if(Player == nullptr){
            bullet->update(0);
        } else {
            bullet->update(Player->getSpeed());
        }
    }

    for(auto passingcar : passingCars){
        if(Player == nullptr) {
            passingcar->update(0);
        } else {
            passingcar->update(Player->getSpeed());
        }
    }


    Collision();
    if(Player != nullptr) {
        calcDistance();
        if (getPlayer()->Delete()) {
            setPlayer(nullptr);
        }

    }
    calcScore();
    notify(score);
}

void roadfighter::World::setBackground(const std::shared_ptr<roadfighter::Entity> &Background) {
    World::Background = Background;
}

void roadfighter::World::update(int speed) {

}

int roadfighter::World::getSpeed() {
    return 0;
}

const std::shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayer() const {
    return Player;
}

const std::vector<std::shared_ptr<roadfighter::Entity>> &roadfighter::World::getPassingCars() const {
    return passingCars;
}

void roadfighter::World::addPassingCar(std::shared_ptr<roadfighter::Entity> car) {
    passingCars.push_back(car);
}

bool roadfighter::World::Delete() {
    return false;
}


void roadfighter::World::Collision() {
    //TODO FIX
    if(getPlayer() != nullptr) {
        std::shared_ptr<ObjBox> PlayerBox = Player->getObjbox();
        double width1 = PlayerBox->centralpos.first - PlayerBox->width / 2;
        double width2 = PlayerBox->centralpos.first + PlayerBox->width / 2;
        double heigth1 = PlayerBox->centralpos.second - PlayerBox->height / 2;
        double heigth2 = PlayerBox->centralpos.second + PlayerBox->height / 2;
        for (auto passingcar : passingCars) {
            //Left upper left lower right upper ...
            std::shared_ptr<ObjBox> carBox = passingcar->getObjbox();
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
                if (tempvec[i].first > width1 and tempvec[i].first < width2) {
                    if (tempvec[i].second < heigth2 and tempvec[i].second > heigth1) {
                        std::cout << "crash" << std::endl;
                        getPlayer()->setDelete(true);
                        crashes++;
                        calcScore();
                        notify(score);
                    }
                }

            }
        }
    }
    //TODO betere namen
    for(auto passingcar : passingCars){
        std::shared_ptr<ObjBox> PassingBox = passingcar->getObjbox();

        double Width1 = PassingBox->centralpos.first - PassingBox->width/2;
        double Width2 = PassingBox->centralpos.first + PassingBox->width/2;
        double Heigth1 = PassingBox->centralpos.second - PassingBox->height/2;
        double Heigth2 = PassingBox->centralpos.second + PassingBox->height/2;

        for(auto bullet: Bullets){
            std::pair<double,double> Position = bullet->getObjbox()->centralpos;

            if( Position.first > Width1-0.05 and Position.first < Width2+0.05){
                if(Position.second > Heigth1){
                    bullet->setDelete(true);
                    passingcar->setDelete(true);
                    destroyedCars++;
                    calcScore();
                    notify(score);
                }
            }


        }
    }

}

ObjBox roadfighter::World::getObjBox() {
    return ObjBox(std::pair<double,double>(), 0, 0);
}

std::shared_ptr<ObjBox> roadfighter::World::getObjbox() {
    return std::shared_ptr<ObjBox>();
}

void roadfighter::World::setDelete(bool del) {

}

bool roadfighter::World::Shoot() {
    return false;
}

bool roadfighter::World::isShoot() const {
    return shoot;
}

void roadfighter::World::addBullet(std::shared_ptr<roadfighter::Entity> bullet) {
    Bullets.push_back(bullet);
}



void roadfighter::World::calcDistance() {

    Distance = Distance + Player->getSpeed()/100;
}

void roadfighter::World::calcScore() {
    int dist = (Distance / 10);
    int destr = destroyedCars *50;
    int crash = crashes*-100;
    score = dist + destr +crash;

}

void roadfighter::World::attach(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void roadfighter::World::notify(int scoreUpdate) {
    for(auto obs : observers){
        obs->update(scoreUpdate);
    }
}
