//
// Created by senne on 1/16/19.
//

#ifndef ROADFIGHTER_SFMLBULLET_H
#define ROADFIGHTER_SFMLBULLET_H

#include "../roadfighter/Bullet.h"
#include <SFML/Graphics.hpp>

namespace roadfighterSFML {
class SFMLBullet : public roadfighter::Bullet {
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    void draw() override;
    SFMLBullet(const std::shared_ptr<sf::RenderWindow> window, double first , double second);

};
}

#endif //ROADFIGHTER_SFMLBULLET_H
