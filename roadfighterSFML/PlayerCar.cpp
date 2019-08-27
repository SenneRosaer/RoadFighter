//
// Created by senne on 12/15/18.
//

#include "PlayerCar.h"
#include "../Exception_class/SpriteLoadError.h"
#include "../Singleton/Transformation.h"

roadfighterSFML::PlayerCar::PlayerCar(const std::shared_ptr<sf::RenderWindow> window, int level,
                                      std::shared_ptr<ConfigData> config)
    : roadfighter::PlayerCar(config)
{
        this->window = window;
        this->level = level;

        // Loads the texture
        try {
                const char* file = roadfighter::Entity::Config->getPlayer().c_str();
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

void roadfighterSFML::PlayerCar::draw()
{
        // transforms position and draws
        std::pair<double, double> position =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform(centralpos);
        sprite.setPosition(position.first, position.second);
        window->draw(sprite);
}

void roadfighterSFML::PlayerCar::update()
{

        // checks for input and gives it to the logic side
        std::vector<std::string> inputs;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                inputs.push_back("right");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                inputs.push_back("left");
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
                //azerty difference
                inputs.push_back("left");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                inputs.push_back("space");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                inputs.push_back("up");
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
                inputs.push_back("up");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                inputs.push_back("down");
        }

        roadfighter::PlayerCar::update();

        UpdateMovement(inputs);
}
