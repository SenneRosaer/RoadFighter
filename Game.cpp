//
// Created by senne on 12/15/18.
//

#include "Game.h"
#include "roadfighterSFML/SFMLFactory.h"
#include "Singleton/Random.h"
#include "Observer/ObserverScore.h"
#include <ctime>
#include <chrono>
#include <thread>

void Game::run() {


    //TODO op c++ manier oplossen
    //window->setFramerateLimit(30);
    std::shared_ptr<ObserverScore> obs = std::make_shared<ObserverScore>(world,window);

    std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point b = std::chrono::system_clock::now();


    std::chrono::system_clock::time_point test;
    std::chrono::system_clock::time_point test2;





    bool first = true;
    while (window->isOpen())
    {
        a = std::chrono::system_clock::now();
        std::chrono::duration<double,std::milli> frameTime = a -b;

        if(frameTime.count() < 33){
            std::chrono::duration<double,std::milli > t(33 - frameTime.count());
            auto tDuration = std::chrono::duration_cast<std::chrono::milliseconds>(t);
            std::this_thread::sleep_for(std::chrono::milliseconds(tDuration.count()));
        }

        b = std::chrono::system_clock::now();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }


        std::chrono::duration<double,std::milli > testing = test - std::chrono::system_clock::now();
        if(first or testing.count() < -1000) {
            if(world->getPlayer() != nullptr) {
                if (world->getPlayer()->getSpeed() > 150 && world->getPassingCars().size() < 5) {
                    first = false;
                    test = std::chrono::system_clock::now();
                    std::chrono::duration<double, std::milli> t2 = test - b;
                    world->addPassingCar(factory->createPassingCar(Random::getInstance().getRandom()));

                }
            }
        }

        window->clear();

        world->update();
        if(world->getPlayer() == nullptr and world->respawnTimer == 0){
            world->setPlayer(factory->createPlayerCar());
            world->respawnTimer = 30;
        }else if(world->getPlayer() == nullptr){
            world->respawnTimer--;
        }
        if(world->isShoot()){
            double first = world->getPlayer()->getObjbox()->centralpos.first;
            double second = world->getPlayer()->getObjbox()->centralpos.second;
            world->addBullet(factory->createBullet(first,second));
        }

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

