//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include "../Utils/Utils.h"
#include "../ConfigData.h"
#include <memory>

namespace roadfighter {
class Entity : public std::enable_shared_from_this<roadfighter::Entity>
{
protected:
    /**
     * Configuration data
     */
    std::shared_ptr<ConfigData> Config;

public:

        /**
         * Draw an object
         */
        virtual void draw() = 0;

        /**
         * Update an object
         */
        virtual void update() = 0;

        /**
         * Update an object with a speed
         * @param speed
         */
        virtual void update(int speed, std::shared_ptr<roadfighter::Entity> Player) = 0;

        /**
         * Return the speed of an object
         * @return
         */
        virtual int getSpeed() = 0;

    /**
     * Returns a certain value to determine the delete status
     * 0 = nothing, 1 = delete, 2 = respawn
     * @return
     */
        virtual int Delete() = 0;

        /**
         * Set if an object must be deleted
         * @param del
         */
        virtual void setDelete(int del) = 0;

        /**
         * Return if an object must shoot
         * @return
         */
        virtual bool Shoot() = 0;

        /**
         * Return the object box of an object
         * @return
         */
        virtual std::shared_ptr<ObjBox> getObjbox() = 0;
};

} // namespace roadfighter

#endif // ROADFIGHTER_ENTITY_H
