//
// Created by senne on 12/15/18.
//

#include "Game.h"
#include "roadfighterSFML/SFMLFactory.h"


void Game::run() {


    //TODO op c++ manier oplossen
    window->setFramerateLimit(30);


    while (window->isOpen())
    {


        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        world->update();
        window->clear();

        /*
        sf::Texture testTexture;
        testTexture.loadFromFile("../Sprites/road.piko");
        //154 192  77  96
        sf::Sprite testrect;
        testrect.setTexture(testTexture);
        //testrect.setOrigin(77,96);
        testrect.scale(1.6,2);
        window->draw(testrect);
        */

        world->draw();



        window->display();
    }

}

Game::Game() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800,600),"TheGame");
    world = std::make_shared<roadfighter::World>();
    factory = std::make_shared<roadfighterSFML::SFMLFactory>(window);

    world->setPlayer(factory->createPlayerCar());
    world->setBackground(factory->createBackground());

}
