//
// Created by senne on 12/15/18.
//

#include "Game.h"


void Game::run() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(300,400),"TheGame");


    while (window.get()->isOpen())
    {


        sf::Event event;
        while (window.get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.get()->close();
        }

        window.get()->clear();
        window.get()->display();




    }

}
