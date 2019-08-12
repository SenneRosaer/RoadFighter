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

        int respawntimer;

        int respawntimeVal;

        bool disableActions = false;

        bool finished = false;

        int maxspeed;

        int acceleration;

        double sidemovement = 0;

    private:
    public:
        /**
         * Constructor with the configuration data
         * @param config
         */
        AIRacer( std::shared_ptr<ConfigData> config);

        /**
         * Update function from the entity with parameters which is not used in this class but has to be specified
         * because it is pure virtual in entity
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
         * Returns a certain value to determine the delete status
         * 0 = nothing, 1 = delete, 2 = respawn
         * @return
         */
        int Delete() override;

        /**
         * Set the delete variable to a certain value
         * @param del
         */
        void setDelete(int del) override;

        /**
         * Returns if we need to shoot but this function is only used for the player so returns false
         * @return
         */
        bool Shoot() override;

        /**
         * Return the object box of the object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Updates the object without parameters
         * Checks when the ai has passed the finish and also controls the respawn timer
         */
        void update() override;

        /**
         * Updates the movement of the ai based on the other obstacles in the game
         * it takes the object closest to the front of the car and then moves accordingly
         * Also updates the speed of the AI
         * @param passingCars
         * @param MovingCars
         * @param Rocks
         * @param player
         */
        void updateMovement(std::vector<std::shared_ptr<roadfighter::Entity>> passingCars,std::vector<std::shared_ptr<roadfighter::Entity>> MovingCars,std::vector<std::shared_ptr<roadfighter::Entity>> Rocks, std::shared_ptr<roadfighter::Entity> player);

        /**
         * Return the distance the AI has travelled
         * @return
         */
        int getCarTravelledDistance() const;
    };
}

#endif //ROADFIGHTER_AIRACER_H
