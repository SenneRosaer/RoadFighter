//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include "../ConfigData.h"
#include "../Utils/Utils.h"
#include <memory>

namespace roadfighter {
/**
 * Holds all the entities that can exist in the game
 * most are splitted in a logic and SFML part except for the world
 */
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
         * Updates the entity with the speed of the player and the player
         * @param speed
         * @param Player
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
