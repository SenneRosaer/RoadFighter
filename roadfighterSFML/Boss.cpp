//
// Created by sennerosaer on 8/8/19.
//

#include "Boss.h"
#include "../Exception_class/SpriteLoadError.h"
#include "../Singleton/Transformation.h"

void roadfighterSFML::Boss::draw()
{
        // Transforms the positions and draws
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

roadfighterSFML::Boss::Boss(const std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<ConfigData> config)
    : roadfighter::Boss(config)
{
        this->window = window;
        // load texture
        const char* file = config->getBoss().c_str();
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
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.scale(1.3, 1.3);

        height =
            Transformation::getInstance(window->getSize().x, window->getSize().y).heightReverse(texture.getSize().y);
        width = Transformation::getInstance(window->getSize().x, window->getSize().y).widthReverse(texture.getSize().x);
}
