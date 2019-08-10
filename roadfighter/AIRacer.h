//
// Created by sennerosaer on 8/7/19.
//

#ifndef ROADFIGHTER_AIRACER_H
#define ROADFIGHTER_AIRACER_H


#include "Entity.h"
#include "vector"

namespace roadfighter {
    class AIRacer : public roadfighter::Entity {
    protected:
        double height;

        double width;

        std::pair<double, double> centralpos = {-1.3, -2};

        int speed = 0;

        int toDel = 0;

        int CarTravelledDistance = 0;

        int respawntimer = 45;

        bool disableActions = false;

        bool finished = false;

        int maxspeed = 190;

        double sidemovement = 0;

    private:
    public:
        void draw() override;

        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        int getSpeed() override;

        int Delete() override;

        void setDelete(int del) override;

        bool Shoot() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        void update() override;

        void updateMovement(std::vector<std::shared_ptr<roadfighter::Entity>> passingCars,std::vector<std::shared_ptr<roadfighter::Entity>> MovingCars,std::vector<std::shared_ptr<roadfighter::Entity>> Rocks, std::shared_ptr<roadfighter::Entity> player);

        int getCarTravelledDistance() const;
    };
}

#endif //ROADFIGHTER_AIRACER_H
