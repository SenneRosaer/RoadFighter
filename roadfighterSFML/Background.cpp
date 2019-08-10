//
// Created by senne on 12/16/18.
//

#include "Background.h"
#include "../Singleton/Transformation.h"
#include "../Exception_class/GameError.h"
#include "../Exception_class/SpriteLoadError.h"


roadfighterSFML::Background::Background(const std::shared_ptr<sf::RenderWindow> &window, int type) : window(
        window) {
    // TODO fix properheid of andere manier
    std::string filename = "../Sprites/road" + std::to_string(type) + ".png";


    try {
        if (!texture.loadFromFile(filename)) {
            throw (SpriteLoadError());
        }

        if (type != 3) {
            std::string filenamefin = "../Sprites/road" + std::to_string(type) + "Fin.png";
            if (!fintexture.loadFromFile(filenamefin)) {
                throw (SpriteLoadError());
            }

        } else {
            std::string filenamefin = "../Sprites/rod" + std::to_string(type) + ".png";
            if (!fintexture.loadFromFile(filenamefin)) {
                throw (SpriteLoadError());
            }
        }
    } catch (GameError &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }


    BG1.setSize(sf::Vector2f((window->getSize().x / 2), window->getSize().y));
    BG1.setOrigin(window->getSize().x / 4, (window->getSize().y));
    BG1.setTexture(&texture);


    BG2 = BG1;
    BG3 = BG1;
    BGFIN = BG1;
    BGFIN.setTexture(&fintexture);

    if (type == 3) {
        bossfight = true;
    }
    //https://en.sfml-dev.org/forums/index.php?topic=10660.0
    /*
     * eerst texture me al die dingen
     * texture scalen naar window
     * laatste twee van rect zijn window size
     * eerste twee positie
     * dus van de eerste twee y veranderen om te moven
     *
     */
}

void roadfighterSFML::Background::draw() {

    //maxdistance - 6600 87200

    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos1);
    std::pair<double, double> position2 =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos2);
    std::pair<double, double> position3 =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos3);
    std::pair<double, double> positionfin =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralposfin);

    BG1.setPosition(position.first, position.second);
    BG2.setPosition(position2.first, position2.second);
    BG3.setPosition(position3.first, position3.second);
    BGFIN.setPosition(positionfin.first, position3.second);

    window->draw(BG1);
    window->draw(BG2);
    window->draw(BG3);

    if (CarTravelledDistance > 93900) {
        if (!finishDrawed and !moveFinish) {


            moveFinish = true;
            finishDrawed = true;
        }
    }
    if (moveFinish) {
        window->draw(BGFIN);
    }
}



