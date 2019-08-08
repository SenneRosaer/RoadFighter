//
// Created by sennerosaer on 8/8/19.
//

#ifndef ROADFIGHTER_BOSS_H
#define ROADFIGHTER_BOSS_H

#include <iostream>
#include "Entity.h"
#include "vector"
namespace roadfighter {
    class Boss : public roadfighter::Entity {
    protected:
        double height;

        double width;

        std::pair<double, double> centralpos = {-0.9, 3.2};

        int Startspeed = 90;

        int endSpeed = 100;

        int currentspeed;

        int toDel = 0;

        int CarTravelledDistance = 0;

        int respawntimer = 60;

        bool disableActions = false;

        bool finished = false;

        int maxspeed = 190;

        double sidemovement = 0;

        std::string move = "left";

        int attackTimer = 60;

        std::vector<double> rockPos;

        bool getRocks = false;

        int life = 1;

    public:
        void update() override;

        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        int getSpeed() override;

        int Delete() override;

        void setDelete(int del) override;

        bool Shoot() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        bool isGetRocks() const;

        void setGetRocks(bool getRocks);

        const std::vector<double> &getRockPos() const;

        int getLife() const;

        void setLife(int life);

    };
}


#endif //ROADFIGHTER_BOSS_H
