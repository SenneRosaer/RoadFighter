//
// Created by senne on 12/16/18.
//

#include "Background.h"
#include "../Exception_class/GameError.h"
#include "../Exception_class/SpriteLoadError.h"
#include "../Singleton/Transformation.h"

roadfighterSFML::Background::Background(const std::shared_ptr<sf::RenderWindow>& window, int type,
                                        std::shared_ptr<ConfigData> config)
    : window(window), roadfighter::Background(config)
{
        // TODO fix properheid of andere manier
        std::string filename;
        std::string filenamefin;
        if (type == 1) {
                filename = config->getBackground1();
                filenamefin = config->getBackground1Fin();
        } else if (type == 2) {
                filename = config->getBackground2();
                filenamefin = config->getBackground2Fin();
        } else if (type == 3) {
                filename = config->getBackground3();
                filenamefin = config->getBackground3Fin();
        }

        try {
                if (!texture.loadFromFile(filename)) {
                        throw(SpriteLoadError(filename.c_str()));
                }
                if (!fintexture.loadFromFile(filenamefin)) {
                        throw(SpriteLoadError(filenamefin.c_str()));
                }

        } catch (FileError& e) {
                std::string test = e.what();
                std::cerr << e.what() << e.filePath() << std::endl;
                throw;
        }

        // Creates 3 copies of the background to make a continuous sprite
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
}

void roadfighterSFML::Background::draw()
{

        // Transforms the positions and draws them
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


        // If we passed a certain distance draw the finish
        if (CarTravelledDistance >= roadfighter::Entity::Config->getDistance() - 6200 and CarTravelledDistance <= roadfighter::Entity::Config->getDistance() - 5900) {
                if (!finishDrawed and !moveFinish) {

                        moveFinish = true;
                        finishDrawed = true;
                }
        }
        if (moveFinish) {
                window->draw(BGFIN);
        }
}
