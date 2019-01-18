//
// Created by senne on 1/16/19.
//

#include "SFMLBullet.h"
#include "../Singleton/Transformation.h"

void roadfighterSFML::SFMLBullet::draw()
{
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(pos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

roadfighterSFML::SFMLBullet::SFMLBullet(const std::shared_ptr<sf::RenderWindow> window, double first, double second)
{
        this->window = window;
        pos = {first, second};

        texture.loadFromFile("../Sprites/Bullet.piko");
        texture.setSmooth(true);

        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.scale(1.3, 1.3);
}
