//
// Created by sennerosaer on 8/11/19.
//

#ifndef ROADFIGHTER_CONFIGDATA_H
#define ROADFIGHTER_CONFIGDATA_H

#include "iostream"

class ConfigData {
private:
    //Files

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

    //Variables
        int distance;
        //AI
        int respawnTimerAI;
        int maxSpeedAI;
        int accelerationAI;

        //Player
        int respawnTimerPlayer;
        int maxSpeedPlayer;
        int accelerationPlayer;
        int bossfightSpeed;
        int reloadSpeed;

        //PassingCar
        int maxSpeedPassingCar;

        //Bullet
        int bulletSpeed;

        //Boss
        int lifes;
        int attackTimer;

        //Extra
        int GameEndingTimer;
        int CarSpawnTimer;
        int RockSpawnTimer;


public:
    /**
     * Constructor that parses the config file
     * @param filename
     */
    ConfigData(std::string filename);

    //Files

    const std::string &getFont() const;

    const std::string &getLevel1() const;

    const std::string &getLevel2() const;

    const std::string &getLevel3() const;

    const std::string &getHighscore() const;

    const std::string &getAi() const;

    const std::string &getBackground1() const;

    const std::string &getBackground2() const;

    const std::string &getBackground3() const;

    const std::string &getBackground1Fin() const;

    const std::string &getBackground2Fin() const;

    const std::string &getBackground3Fin() const;

    const std::string &getBoss() const;

    const std::string &getBullet() const;

    const std::string &getMovingCar() const;

    const std::string &getPassingCar() const;

    const std::string &getPlayer() const;

    const std::string &getRock() const;

    int getRespawnTimerAi() const;

    int getMaxSpeedAi() const;

    int getAccelerationAi() const;

    int getDistance() const;

    int getRespawnTimerPlayer() const;

    int getMaxSpeedPlayer() const;

    int getAccelerationPlayer() const;

    int getBossfightSpeed() const;

    int getReloadSpeed() const;

    int getMaxSpeedPassingCar() const;

    int getBulletSpeed() const;

    int getLifes() const;

    int getAttackTimer() const;

    int getGameEndingTimer() const;

    int getCarSpawnTimer() const;

    int getRockSpawnTimer() const;

    void setBackground1(const std::string &background1);

    void setBackground2(const std::string &background2);

    void setBackground3(const std::string &background3);

    void setBackground1Fin(const std::string &background1Fin);

    void setBackground2Fin(const std::string &background2Fin);

    void setBackground3Fin(const std::string &background3Fin);


};






#endif //ROADFIGHTER_CONFIGDATA_H
