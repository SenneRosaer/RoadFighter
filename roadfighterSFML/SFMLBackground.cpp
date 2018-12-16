//
// Created by senne on 12/16/18.
//

#include "SFMLBackground.h"
#include "../Singleton/Transformation.h"

roadfighterSFML::SFMLBackground::SFMLBackground(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    texture.loadFromFile("../Sprites/road2.png");

    /*
    sprite1.setTexture(texture);
    sprite1.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    //TODO beter manier om de sprite te fitten aan het scherm;
    sprite1.scale(3.347,3.896);


    sprite2.setTexture(texture);
    sprite2.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite2.scale(3.347,3.896);
    */
    //TODO scalen voor hele scherm te overlappen
    //Tweede sprite bijhouden voor andere afbeelding






    BG1.setSize(sf::Vector2f(window->getSize().x/2,window->getSize().y));
    BG1.setOrigin(window->getSize().x/4,window->getSize().y/2);
    BG1.setTexture(&texture);

    BG2 = BG1;
}

void roadfighterSFML::SFMLBackground::draw() {
    std::pair<float,float> position = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos1);
    std::pair<float,float> position2 = Transformation::getInstance(window->getSize().x,window->getSize().y).Transform(centralpos2);

    BG1.setPosition(position.first,position.second);
    BG2.setPosition(position2.first,position2.second);

    window->draw(BG1);
    window->draw(BG2);
}

