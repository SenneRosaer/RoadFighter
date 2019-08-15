//
// Created by senne on 1/16/19.
//

#include "Bullet.h"
#include "../Exception_class/SpriteLoadError.h"
#include "../Singleton/Transformation.h"

void roadfighterSFML::Bullet::draw()
{
        // transforms positions and draws
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(pos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

roadfighterSFML::Bullet::Bullet(const std::shared_ptr<sf::RenderWindow> window, double first, double second,
                                std::shared_ptr<ConfigData> config)
    : roadfighter::Bullet(config)
{
        this->window = window;
        pos = {first, second};
        // Loads texture
        const char* file = config->getBullet().c_str();
        try {
                if (!texture.loadFromFile(file)) {
                        throw(SpriteLoadError(file));
                }
        } catch (FileError& e) {
                std::cerr << e.what() << e.filePath() << std::endl;
                throw;
        }
        texture.setSmooth(true);

        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2, 0);
        sprite.scale(1.3, 1.3);
}
