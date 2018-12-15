//
// Created by senne on 12/15/18.
//

#include "Game.h"
#include "roadfighterSFML/SFMLFactory.h"


void Game::run() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(300,400),"TheGame");
    world = std::make_shared<roadfighter::World>();
    roadfighterSFML::SFMLFactory Factory(window);


    while (window->isOpen())
    {


        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        world->setPlayer(Factory.createPlayerCar());
        world->draw();
        window->display();
    }

}
