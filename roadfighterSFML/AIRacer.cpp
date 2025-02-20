//
// Created by sennerosaer on 8/7/19.
//

#include "AIRacer.h"

#include "../Exception_class/SpriteLoadError.h"
#include "../Singleton/Transformation.h"
#include <utility>

roadfighterSFML::AIRacer::AIRacer(const std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<ConfigData> config)
    : roadfighter::AIRacer(std::move(config))
{

        this->window = window;
        // loads the texture
        try {
                const char* file = roadfighter::Entity::Config->getAi().c_str();
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

void roadfighterSFML::AIRacer::draw()
{
        // Transform to window positions
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

void roadfighterSFML::AIRacer::update() {}
