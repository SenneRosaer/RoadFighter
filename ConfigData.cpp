//
// Created by sennerosaer on 8/11/19.
//

#include <fstream>
#include "ConfigData.h"
#include "JSON/single_include/nlohmann/json.hpp"
#include "Exception_class/FileError.h"

using json = nlohmann::json ;

ConfigData::ConfigData(std::string filename) {
    try {



        std::ifstream ifstr(filename);
        json js = json::parse(ifstr);

        //Files

        Font = js["FilePaths"]["Font"];
        Level1 = js["FilePaths"]["Level1"];
        Level2 = js["FilePaths"]["Level2"];
        Level3 = js["FilePaths"]["Level3"];
        Highscore = js["FilePaths"]["Highscore"];
        AI = js["FilePaths"]["AI"];
        Background1 = js["FilePaths"]["Background1"][0];
        Background1Fin = js["FilePaths"]["Background1"][1];
        Background2 = js["FilePaths"]["Background2"][0];
        Background2Fin = js["FilePaths"]["Background2"][1];
        Background3 = js["FilePaths"]["Background3"][0];
        Background3Fin = js["FilePaths"]["Background3"][1];
        Boss = js["FilePaths"]["Boss"];
        Bullet = js["FilePaths"]["Bullet"];
        MovingCar = js["FilePaths"]["MovingCar"];
        PassingCar = js["FilePaths"]["PassingCar"];
        Player = js["FilePaths"]["Player"];
        Rock = js["FilePaths"]["Rock"];



        //Variables
        std::string tempDistance = js["Variables"]["Distance"];
        distance = std::stoi(tempDistance);
            //AI
            std::string temp1 =  js["Variables"]["Ai"]["respawnTimer"] ;
            std::string temp2 =  js["Variables"]["Ai"]["maxSpeed"];
            std::string temp3 = js["Variables"]["Ai"]["acceleration"];
            respawnTimerAI = std::stoi(temp1);
            maxSpeedAI = std::stoi(temp2);
            accelerationAI = std::stoi(temp3);

            //Player
            std::string tempRTP = js["Variables"]["Player"]["respawnTimer"];
            std::string tempMSP =  js["Variables"]["Player"]["maxSpeed"];
            std::string tempBFS = js["Variables"]["Player"]["bossFightSpeed"];
            std::string tempAP = js["Variables"]["Player"]["acceleration"];
            std::string tempRS = js["Variables"]["Player"]["reloadSpeed"];

            respawnTimerPlayer = std::stoi(tempRTP);
            maxSpeedPlayer = std::stoi(tempMSP);
            bossfightSpeed = std::stoi(tempBFS);
            accelerationPlayer = std::stoi(tempAP);
            reloadSpeed = std::stoi(tempRS);


    } catch (FileError &e) {
        std::cerr << e.what() << e.filePath() << std::endl;
        throw;
    }


}


const std::string &ConfigData::getFont() const {
    return Font;
}

const std::string &ConfigData::getLevel1() const {
    return Level1;
}

const std::string &ConfigData::getLevel2() const {
    return Level2;
}

const std::string &ConfigData::getLevel3() const {
    return Level3;
}

const std::string &ConfigData::getHighscore() const {
    return Highscore;
}

const std::string &ConfigData::getAi() const {
    return AI;
}

const std::string &ConfigData::getBackground1() const {
    return Background1;
}

const std::string &ConfigData::getBackground2() const {
    return Background2;
}

const std::string &ConfigData::getBackground3() const {
    return Background3;
}

const std::string &ConfigData::getBackground1Fin() const {
    return Background1Fin;
}

const std::string &ConfigData::getBackground2Fin() const {
    return Background2Fin;
}

const std::string &ConfigData::getBackground3Fin() const {
    return Background3Fin;
}

const std::string &ConfigData::getBoss() const {
    return Boss;
}

const std::string &ConfigData::getBullet() const {
    return Bullet;
}

const std::string &ConfigData::getMovingCar() const {
    return MovingCar;
}

const std::string &ConfigData::getPassingCar() const {
    return PassingCar;
}

const std::string &ConfigData::getPlayer() const {
    return Player;
}

const std::string &ConfigData::getRock() const {
    return Rock;
}



//AI
int ConfigData::getRespawnTimerAi() const {
    return respawnTimerAI;
}

int ConfigData::getMaxSpeedAi() const {
    return maxSpeedAI;
}

int ConfigData::getAccelerationAi() const {
    return accelerationAI;
}

//Player
int ConfigData::getDistance() const {
    return distance;
}

int ConfigData::getRespawnTimerPlayer() const {
    return respawnTimerPlayer;
}

int ConfigData::getMaxSpeedPlayer() const {
    return maxSpeedPlayer;
}

int ConfigData::getAccelerationPlayer() const {
    return accelerationPlayer;
}

int ConfigData::getBossfightSpeed() const {
    return bossfightSpeed;
}

int ConfigData::getReloadSpeed() const {
    return reloadSpeed;
}
