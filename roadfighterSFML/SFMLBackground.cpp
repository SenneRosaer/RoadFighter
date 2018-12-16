//
// Created by senne on 12/16/18.
//

#include "SFMLBackground.h"
#include "../Singleton/Transformation.h"

roadfighterSFML::SFMLBackground::SFMLBackground(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    //TODO fix properheid of andere manier
    texture.loadFromFile("../Sprites/road2.png");



    BG1.setSize(sf::Vector2f(window->getSize().x/2,window->getSize().y+200));
    BG1.setOrigin(window->getSize().x/4,(window->getSize().y/2) + 100);
    BG1.setTexture(&texture);
    std::cout << BG1.getSize().y << std::endl;
    BG2 = BG1;
    BG3 = BG1;
}

void roadfighterSFML::SFMLBackground::draw() {
    std::pair<float,float> position = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos1);
    std::pair<float,float> position2 = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos2);
    std::pair<float,float> position3 = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos3);


    BG1.setPosition(position.first,position.second);
    BG2.setPosition(position2.first,position2.second);
    BG3.setPosition(position3.first,position3.second);


    //BG1.move(0,1);


    //sprite.move(0,1);
    //BG1.move(1,0);
    window->draw(BG1);
    window->draw(BG2);
    window->draw(BG3);

}

