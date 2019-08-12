//
// Created by senne on 1/16/19.
//

#ifndef ROADFIGHTER_BULLET_H
#define ROADFIGHTER_BULLET_H

#include "Entity.h"

namespace roadfighter {
class Bullet : public roadfighter::Entity
{
protected:
        int speed;
        std::pair<double, double> pos;
        int toDel = 0;

public:

    /**
     * Constructor with configuration data
     * @param config
     */
    Bullet(std::shared_ptr<ConfigData> config);

    /**
         * Updates the object with extra parameters
         * @param speed
         * @param Player
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Update the object
         */
        void update() override;

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
         * Set if an object must be deleted
         * @param del
         */
        void setDelete(int del) override;

        /**
         * Return the object box of an object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Return if an object must shoot;
         * @return
         */
        bool Shoot() override;
};
} // namespace roadfighter

#endif // ROADFIGHTER_BULLET_H
