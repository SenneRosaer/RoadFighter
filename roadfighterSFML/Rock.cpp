//
// Created by sennerosaer on 7/22/19.
//

#include "Rock.h"
#include "../Exception_class/SpriteLoadError.h"
#include "../Singleton/Transformation.h"

void roadfighterSFML::Rock::draw()
{
        // Transforms positions and draws
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

roadfighterSFML::Rock::Rock(std::shared_ptr<sf::RenderWindow> window, double i, std::shared_ptr<ConfigData> config)
{
        roadfighter::Entity::Config = config;
        this->window = window;
        // sets position
        centralpos = {i, 3.5};

        // Loads texture
        this->window = window;
        const char* file = config->getRock().c_str();
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

        height = Transformation::getInstance(window->getSize().x, window->getSize().y)
                     .heightReverse(sprite.getLocalBounds().height);
        width = Transformation::getInstance(window->getSize().x, window->getSize().y)
                    .widthReverse(sprite.getLocalBounds().width);
}
