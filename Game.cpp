//
// Created by senne on 12/15/18.
//

#include "Game.h"
#include "Observer/ObserverScore.h"
#include "Singleton/Random.h"
#include "roadfighterSFML/SFMLFactory.h"
#include "Singleton/Transformation.h"
#include "Observer/ObserverStartRace.h"
#include <chrono>
#include <ctime>
#include <thread>
using json = nlohmann::json;


void Game::run() {


    std::shared_ptr<ObserverScore> obs = std::make_shared<ObserverScore>(window);
    std::shared_ptr<ObserverStartRace> obs2 = std::make_shared<ObserverStartRace>(window);

    world->attach(obs);
    world->attach(obs2);



    bool first = true;
    bool first2 = true;
    bool first3 = true;
    bool menuActive = true;
    bool bossCreated = false;
    int RockTimer = 80;
    int Car1Timer = 25;


    //TEST
    const int FPS = 30;
    const int framdelay = 1000/FPS;
    int framestart;
    int frametime;
    //

    int level;

    auto nextFrame = std::chrono::steady_clock::now();

    while (window->isOpen()) {

        nextFrame +=  std::chrono::milliseconds(33);

        if (!menuActive) {




            if (first or Car1Timer <= 0) {
                if (world->getPlayer() != nullptr) {
                    int random = Random::getInstance().getRandom2();
                    if(world->passingCar and !world->movingCar){
                        random= 0;
                    } else if(!world->passingCar and !world->movingCar){
                        random = 2;
                    } else if(!world->passingCar and world->movingCar){
                        random = 1;
                    }
                    switch (random) {
                        case 0:
                            if (world->getPlayer()->getSpeed() > 150 && world->getPassingCars().size() < 7) {
                                first = false;
                                world->addPassingCar(
                                        factory->createPassingCar(Random::getInstance().getRandom()));
                                Car1Timer = 25;
                            }
                            break;
                        case 1:
                            if (world->getPlayer()->getSpeed() > 150 && world->getMovingCars().size() < 4) {
                                first = false;
                                world->addMovingCar(
                                        factory->createMovingCar(Random::getInstance().getRandom()));
                                Car1Timer = 25;
                            }
                            break;
                        default:
                            break;

                    }
                }
            } else {
                Car1Timer--;
            }


            if(world->rock) {
                if (first2 or RockTimer <= 0) {
                    if (world->getPlayer() != nullptr) {
                        if (world->getPlayer()->getSpeed() > 150) {
                            first2 = false;
                            RockTimer = 80;
                            world->addRock(
                                    factory->createRock(Random::getInstance().getRandom3()));
                        }
                    }
                } else {
                    RockTimer--;
                }
            }



            window->clear();
            world->draw();

            world->update();


            if(world->isGameEnding()){
                sf::Font font;
                sf::Text text;
                if (!font.loadFromFile("../Observer/arial.ttf")) {
                    std::cout << "cant load font" << std::endl;
                }
                text.setFont(font);
                // text.setFillColor(sf::Color::White);
                text.setCharacterSize(30);
                text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
                text.setString("Congratulations!!");
                std::pair<double, double> t =
                        Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({-1.8, 0});
                text.setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
                window->draw(text);
            }


            if(!world->isLevelStarted() and world->getTimerInFrames() >0){
                world->setTimerInFrames(world->getTimerInFrames() - 1);
            } else if( world->getTimerInFrames() <= 0){
                world->setLevelStarted(true);
                world->setTimerInFrames(90);
                world->setPlayer(factory->createPlayerCar(level));
                world->setAi(factory->createAI());
            }

            if (world->isShoot()) {
                //TODO andere benaming voor first
                double first = world->getPlayer()->getObjbox()->centralpos.first;
                double second = world->getPlayer()->getObjbox()->centralpos.second;
                world->addBullet(factory->createBullet(first, second));
            }

            if(world->isLevelFinished() and world->getWorldResetTimer() <=0){
                if(world->getCurrentLevel() < 3) {
                    world->reset();
                    Parse(world->getCurrentLevel() + 1);
                }
            } else if (world->getWorldResetTimer() > 0){
                world->setWorldResetTimer(world->getWorldResetTimer()-1);
            }

            if(world->getCurrentLevel() == 3 and world->isBossFight() and bossCreated == false){
                world->setBoss(factory->createBoss());
                bossCreated = true;
            }

            if(bossCreated and world->getBoss() != nullptr) {
                if (world->getBoss()->isGetRocks()) {
                    world->getBoss()->setGetRocks(false);
                    for (auto pos:world->getBoss()->getRockPos()) {
                        world->addRock(factory->createRock(pos));
                    }
                }
            }


            window->display();
            sf::Event event;
            while (window->pollEvent(event)) {
                switch(event.type){
                    case sf::Event::KeyReleased:
                        switch(event.key.code){

                            case sf::Keyboard::Escape:
                                menuActive = true;
                                world->reset();
                                break;



                        }
                }
                if (event.type == sf::Event::Closed)
                    window->close();
            }
        } else {



            sf::Event event;
            while (window->pollEvent(event)) {
                switch(event.type){
                    case sf::Event::KeyReleased:
                        switch(event.key.code){

                            case sf::Keyboard::Up:
                                menu->Up();
                                break;

                            case sf::Keyboard::Down:
                                menu->Down();
                                break;

                            case sf::Keyboard::Escape:
                                window->close();
                                break;

                            case sf::Keyboard::Return:
                                menu->GetSelected();
                                menuActive = false;
                                Parse(menu->GetSelected());
                                level = menu->GetSelected();
                                //of cases per level
                                break;


                    }
                }
                if (event.type == sf::Event::Closed)
                    window->close();
            }


            window->clear();
            menu->drawMenu();
            window->display();
        }

        std::this_thread::sleep_until(nextFrame);
    }



}

Game::Game() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "TheGame");
    world = std::make_shared<roadfighter::World>();
    factory = std::make_shared<roadfighterSFML::SFMLFactory>(window);
    menu = std::make_shared<Menu>(window);


}

void Game::Parse(int level) {

    std::string file = "../JSON/Level"+ std::to_string(level) + ".json";
    std::cout << file << std::endl;
    std::ifstream ifstr(file);
    json js = json::parse(ifstr);

    std::string background = js["background"];
    std::vector<std::string> enemies = js["enemies"];
    for(auto item : enemies){
        if(item == "car1"){
            world->passingCar = true;
        }
        if(item == "rock"){
            world->rock = true;
        }
        if(item == "car2"){
            world->movingCar = true;
        }
    }

    world->setCurrentLevel(level);
    world->setBackground(factory->createBackground(level));
    world->setLevelFinished(false);


}
