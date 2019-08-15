//
// Created by sennerosaer on 8/11/19.
//

#ifndef ROADFIGHTER_CONFIGDATA_H
#define ROADFIGHTER_CONFIGDATA_H

#include "iostream"

/**
 * Holds all the data given by the configuration file
 */
class ConfigData
{
private:
        // Files

        std::string Font;
        std::string Level1;
        std::string Level2;
        std::string Level3;
        std::string Highscore;
        std::string AI;
        std::string Background1;
        std::string Background2;
        std::string Background3;
        std::string Background1Fin;
        std::string Background2Fin;
        std::string Background3Fin;
        std::string Boss;
        std::string Bullet;
        std::string MovingCar;
        std::string PassingCar;
        std::string Player;
        std::string Rock;

        // Variables
        int distance;
        // AI
        int respawnTimerAI;
        int maxSpeedAI;
        int accelerationAI;

        // Player
        int respawnTimerPlayer;
        int maxSpeedPlayer;
        int accelerationPlayer;
        int bossfightSpeed;
        int reloadSpeed;

        // PassingCar
        int maxSpeedPassingCar;

        // Bullet
        int bulletSpeed;

        // Boss
        int lifes;
        int attackTimer;

        // Extra
        int GameEndingTimer;
        int CarSpawnTimer;
        int RockSpawnTimer;

public:
        /**
         * Constructor that parses the config file
         * @param filename
         */
        ConfigData(std::string filename);

        // Files

        /**
         * Getter for the font
         * @return
         */
        const std::string& getFont() const;

        /**
         * Getter for the first level file
         * @return
         */
        const std::string& getLevel1() const;

        /**
         * Getter for the second level file
         * @return
         */
        const std::string& getLevel2() const;

        /**
         * Getter for the third level file
         * @return
         */
        const std::string& getLevel3() const;

        /**
         * Getter for the high-score file
         * @return
         */
        const std::string& getHighscore() const;

        /**
         * Getter for the AI sprite
         * @return
         */
        const std::string& getAi() const;

        /**
         * Getter for the level 1 background sprite
         * @return
         */
        const std::string& getBackground1() const;

        /**
         * Getter for the level 2 background sprite
         * @return
         */
        const std::string& getBackground2() const;

        /**
         * Getter for the level 3 background sprite
         * @return
         */
        const std::string& getBackground3() const;

        /**
         * Getter for the level 1 background finish sprite
         * @return
         */
        const std::string& getBackground1Fin() const;

        /**
         * Getter for the level 2 background finish sprite
         * @return
         */
        const std::string& getBackground2Fin() const;

        /**
         * Getter for the level 3 background finish sprite
         * @return
         */
        const std::string& getBackground3Fin() const;

        /**
         * Getter for the boss sprite
         * @return
         */
        const std::string& getBoss() const;

        /**
         * Getter for the bullet sprite
         * @return
         */
        const std::string& getBullet() const;

        /**
         * Getter for the movingcar sprite
         * @return
         */
        const std::string& getMovingCar() const;

        /**
         * Getter for passingcar sprite
         * @return
         */
        const std::string& getPassingCar() const;

        /**
         * Getter for the player sprite
         * @return
         */
        const std::string& getPlayer() const;

        /**
         * Getter for the rock sprite
         * @return
         */
        const std::string& getRock() const;

        /**
         * Getter for the respawntimer for the AI
         * @return
         */
        int getRespawnTimerAi() const;

        /**
         * Getter for the max speed of the AI
         * @return
         */
        int getMaxSpeedAi() const;

        /**
         * Getter for the acceleration of the AI
         * @return
         */
        int getAccelerationAi() const;

        /**
         * Getter for the travel distance
         * @return
         */
        int getDistance() const;

        /**
         * Getter for the respawn timer of the player
         * @return
         */
        int getRespawnTimerPlayer() const;

        /**
         * Getter for the max speed of the player
         * @return
         */
        int getMaxSpeedPlayer() const;

        /**
         * Getter for the acceleration of the player
         * @return
         */
        int getAccelerationPlayer() const;

        /**
         * Getter for the static speed during the bossfight
         * @return
         */
        int getBossfightSpeed() const;

        /**
         * Get the reload speed
         * @return
         */
        int getReloadSpeed() const;

        /**
         * Getter for the max speed of the passingcar
         * @return
         */
        int getMaxSpeedPassingCar() const;

        /**
         * Getter for the bullet speed
         * @return
         */
        int getBulletSpeed() const;

        /**
         * Getter for the lifes of the boss
         * @return
         */
        int getLifes() const;

        /**
         * Getter for the attack timer of the boss (time between attacks)
         * @return
         */
        int getAttackTimer() const;

        /**
         * Getter for the ending timer of the game
         * @return
         */
        int getGameEndingTimer() const;

        /**
         * Getter for the timer to spawn cars (time between cars that spawn)
         * @return
         */
        int getCarSpawnTimer() const;

        /**
         * Getter for the timer to spawn rocks (time between rocks that spawn)
         * @return
         */
        int getRockSpawnTimer() const;

        /**
         * Set the background sprite of level 1
         * @param background1
         */
        void setBackground1(const std::string& background1);

        /**
         * Set the background sprite of level 2
         * @param background2
         */
        void setBackground2(const std::string& background2);

        /**
         * Set the background sprite of level 3
         * @param background3
         */
        void setBackground3(const std::string& background3);

        /**
         * Set the finish sprite of level 1
         * @param background1Fin
         */
        void setBackground1Fin(const std::string& background1Fin);

        /**
         * Set the finish sprite of level 2
         * @param background2Fin
         */
        void setBackground2Fin(const std::string& background2Fin);

        /**
         * Set the finish sprite of level 3
         * @param background3Fin
         */
        void setBackground3Fin(const std::string& background3Fin);
};

#endif // ROADFIGHTER_CONFIGDATA_H
