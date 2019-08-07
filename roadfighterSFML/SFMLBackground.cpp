//
// Created by senne on 12/16/18.
//

#include "SFMLBackground.h"
#include "../Singleton/Transformation.h"


roadfighterSFML::SFMLBackground::SFMLBackground(const std::shared_ptr<sf::RenderWindow> &window, int type) : window(
        window) {
    // TODO fix properheid of andere manier
    std::string filename = "../Sprites/road" + std::to_string(type) + ".png";
    texture.loadFromFile(filename);

    std::string filenamefin = "../Sprites/road" + std::to_string(type) + "Fin.png";
    fintexture.loadFromFile(filenamefin);
    // repeatble intrect sprite (texture,intrect) ??

    BG1.setSize(sf::Vector2f((window->getSize().x / 2), window->getSize().y ));
    BG1.setOrigin(window->getSize().x / 4, (window->getSize().y));
    BG1.setTexture(&texture);


    BG2 = BG1;
    BG3 = BG1;


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

void roadfighterSFML::SFMLBackground::draw() {


    if(CarTravelledDistance > 950 and !finishDrawed){
       if(BG1.getPosition().y < 0 and BG2.getPosition().y < BG1.getPosition().y){
           BG1.setTexture(&fintexture);
           finishDrawed = true;
       }else
        if(BG2.getPosition().y < 0 and BG3.getPosition().y < BG2.getPosition().y){
            BG2.setTexture(&fintexture);

            finishDrawed = true;
        } else
        if(BG3.getPosition().y < 0 and BG1.getPosition().y < BG3.getPosition().y){
            BG3.setTexture(&fintexture);

            finishDrawed = true;
        } else if ( BG3.getPosition().y < 0){
            BG3.setTexture(&fintexture);
            finishDrawed = true;

        } else if (BG2.getPosition().y < 0){
            BG2.setTexture(&fintexture);

            finishDrawed = true;

        } else if (BG1.getPosition().y < 0){
            BG1.setTexture(&fintexture);

            finishDrawed = true;

        }



    }
    std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos1);
    std::pair<double, double> position2 =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos2);
    std::pair<double, double> position3 =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos3);

    BG1.setPosition(position.first, position.second);
    BG2.setPosition(position2.first, position2.second);
    BG3.setPosition(position3.first, position3.second);

    // BG1.move(0,1);

    // sprite.move(0,1);
    //

    window->draw(BG1);
    window->draw(BG2);
    window->draw(BG3);
}



