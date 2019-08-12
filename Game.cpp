//
// Created by senne on 12/15/18.
//

#include "Game.h"
#include "Observer/ObserverScore.h"
#include "Singleton/Random.h"
#include "roadfighterSFML/SFMLFactory.h"
#include "Singleton/Transformation.h"
#include "Observer/ObserverStartRace.h"
#include "Exception_class/FontLoadError.h"
#include <chrono>
#include <ctime>
#include <thread>

using json = nlohmann::json;


void Game::run() {

    //Observers for score and timer at the start of the race
    std::shared_ptr<ObserverScore> obs = std::make_shared<ObserverScore>(window);
    std::shared_ptr<ObserverStartRace> obs2 = std::make_shared<ObserverStartRace>(window);

    world->attach(obs);
    world->attach(obs2);


    //Used to spawn the first car or obstacle before relying on a timer to make sure that the obstacles don't start spawning to late
    bool first = true;
    bool first2 = true;

    //To control if we need to show the menu or game
    bool menuActive = true;
    //Control if we are fighting the boss or not
    bool bossCreated = false;

    //Interval between the spawning of obstacles
    int RockTimer = Config->getRockSpawnTimer();
    int Car1Timer = Config->getCarSpawnTimer();
    //Interval between end of game and moving to scoreboard
    int gameEndingTimer = Config->getGameEndingTimer();
    //Control if we need to show the scoreboard
    bool Scoreboard = false;


    int level;

    //For caculating the framerate we use the clock at the start and then sleep at the end if the time used is less than needed
    auto nextFrame = std::chrono::steady_clock::now();

    while (window->isOpen()) {

        //33 miliseconds = 1 second / 30 fps
        //nextframe is when the next frame should start
        nextFrame += std::chrono::milliseconds(33);

        if (!menuActive) {
            if (!Scoreboard) {

                //For spawning cars
                if (first or Car1Timer <= 0) {
                    if (world->getPlayer() != nullptr) {
                        int random = Random::getInstance().getRandom2();
                        //See which cars we are allowed to spawn
                        if (world->passingCar and !world->movingCar) {
                            random = 0;
                        } else if (!world->passingCar and !world->movingCar) {
                            random = 2;
                        } else if (!world->passingCar and world->movingCar) {
                            random = 1;
                        }
                        switch (random) {
                            case 0:
                                //Only spawn when at a speed higher than the cars we should pass
                                if (world->getPlayer()->getSpeed() > Config->getMaxSpeedPassingCar() &&
                                    world->getPassingCars().size() < 7) {
                                    first = false;
                                    world->addPassingCar(
                                            factory->createPassingCar(Random::getInstance().getRandom()));
                                    Car1Timer = Config->getCarSpawnTimer();
                                }
                                break;
                            case 1:
                                if (world->getPlayer()->getSpeed() > Config->getMaxSpeedPassingCar() &&
                                    world->getMovingCars().size() < 4) {
                                    first = false;
                                    world->addMovingCar(
                                            factory->createMovingCar(Random::getInstance().getRandom()));
                                    Car1Timer = Config->getCarSpawnTimer();
                                }
                                break;
                            default:
                                break;

                        }
                    }
                } else {
                    Car1Timer--;
                }

                //See if we need to spawn rocks
                //world->rock is a boolean to see if rocks are specified in the level file
                if(world->rock) {
                    if (first2 or RockTimer <= 0) {
                        if (world->getPlayer() != nullptr) {
                            if (world->getPlayer()->getSpeed() > Config->getMaxSpeedPassingCar()) {
                                first2 = false;
                                RockTimer = Config->getRockSpawnTimer();
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

                //update our game world
                world->update();

                //try catch for loading the used font
                sf::Font font;
                const char *filename = Config->getFont().c_str();
                try {
                    if (!font.loadFromFile(filename)) {
                        throw (FontLoadError(filename));
                    }
                } catch (FileError &e) {
                    std::cerr << e.what() << e.filePath() << std::endl;
                    throw;
                }

                //Show the lifes of the boss when in bossfight
                if (bossCreated == true and world->getBoss() != nullptr) {
                    sf::Text bossLife;
                    bossLife.setFont(font);
                    bossLife.setCharacterSize(30);
                    bossLife.setOrigin(bossLife.getLocalBounds().width / 2, bossLife.getLocalBounds().height / 2);
                    bossLife.setString("Boss lifes: " + std::to_string(world->getBoss()->getLife()));
                    std::pair<double, double> t =
                            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({1.1, 0.5});
                    bossLife.setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
                    window->draw(bossLife);
                }


                //Showing distance to the next level
                sf::Text textDistanceLeft;
                textDistanceLeft.setFont(font);
                textDistanceLeft.setCharacterSize(30);
                textDistanceLeft.setOrigin(textDistanceLeft.getLocalBounds().width / 2,
                                           textDistanceLeft.getLocalBounds().height / 2);
                textDistanceLeft.setString("Distance left: " + std::to_string(world->getDistanceToNextLevel() / 100));
                std::pair<double, double> t =
                        Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({1.1, -0.5});
                textDistanceLeft.setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
                window->draw(textDistanceLeft);


                //Show ending + timer when to move to scoreboard
                if (world->isGameEnding() and gameEndingTimer > 0) {
                    //Timer
                    gameEndingTimer--;
                    sf::Text text;

                    text.setFont(font);
                    text.setCharacterSize(30);
                    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
                    text.setString("Congratulations!!");
                    std::pair<double, double> t =
                            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({-2, 0});
                    text.setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
                    window->draw(text);
                } else if (gameEndingTimer == 0) {
                    Scoreboard = true;
                    scoreboard->setScoresCurrentGame(world->getFinalscores());
                }

                //Setup of the player and AI at the start of a game
                if (!world->isLevelStarted() and world->getTimerInFrames() > 0) {
                    world->setTimerInFrames(world->getTimerInFrames() - 1);
                } else if (world->getTimerInFrames() <= 0) {
                    world->setLevelStarted(true);
                    world->setTimerInFrames(Config->getGameEndingTimer());
                    world->setPlayer(factory->createPlayerCar(level));
                    world->setAi(factory->createAI());
                }

                //See if we need to create a bullet and if so at which position
                if (world->isShoot()) {
                    double first = world->getPlayer()->getObjbox()->centralpos.first;
                    double second = world->getPlayer()->getObjbox()->centralpos.second +
                                    world->getPlayer()->getObjbox()->height / 2;
                    world->addBullet(factory->createBullet(first, second));
                }

                //Move to next level after completion of previous;
                if (world->isLevelFinished() and world->getWorldResetTimer() <= 0) {
                    if (world->getCurrentLevel() < 3) {
                        world->reset();
                        Parse(world->getCurrentLevel() + 1);
                        level = world->getCurrentLevel();
                    }
                } else if (world->getWorldResetTimer() > 0) {
                    world->setWorldResetTimer(world->getWorldResetTimer() - 1);
                }

                //See if we need to start bossfight
                if (world->getCurrentLevel() == 3 and world->isBossFight() and bossCreated == false) {
                    world->setBoss(factory->createBoss());
                    bossCreated = true;
                }

                //Check if we need to create rocks created by the boss
                if (bossCreated and world->getBoss() != nullptr) {
                    if (world->getBoss()->isGetRocks()) {
                        if (world->getPlayer()->Delete() != 2) {
                            world->getBoss()->setGetRocks(false);
                            for (auto pos:world->getBoss()->getRockPos()) {
                                world->addRock(factory->createRock(pos));
                            }
                        } else {
                            world->getBoss()->setGetRocks(false);
                        }
                    }
                }
                window->display();

                //Exit the game on esc and reset so we go back to the menu
                sf::Event event;
                while (window->pollEvent(event)) {
                    switch (event.type) {
                        case sf::Event::KeyReleased:
                            switch (event.key.code) {

                                case sf::Keyboard::Escape:
                                    menuActive = true;
                                    world->reset();
                                    bossCreated = false;
                                    world->setFinalscores({});
                                    break;


                            }
                    }
                    if (event.type == sf::Event::Closed)
                        window->close();
                }
            } else {
                window->clear();
                scoreboard->drawBoard();

                window->display();
                //When pressing esc during the scoreboard exit the game
                sf::Event event;
                while (window->pollEvent(event)) {
                    switch (event.type) {
                        case sf::Event::KeyReleased:
                            switch (event.key.code) {

                                case sf::Keyboard::Escape:
                                    window->close();
                                    break;


                            }
                    }
                    if (event.type == sf::Event::Closed)
                        window->close();
                }

            }

        } else {

            //All the actions for selecting a level in the menu
            sf::Event event;
            while (window->pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {

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

        //Sleep if we used less time for a frame than needed
        std::this_thread::sleep_until(nextFrame);
    }


}

Game::Game() {
    //Initializing screen
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "TheGame");
    //Read the configuration file
    Config = std::make_shared<ConfigData>("../JSON/Config.json");
    //create other needed objects
    world = std::make_shared<roadfighter::World>(Config);
    factory = std::make_shared<roadfighterSFML::SFMLFactory>(window, Config);
    menu = std::make_shared<Menu>(window,Config);
    scoreboard = std::make_shared<Scoreboard>(window,Config);

}

void Game::Parse(int level) {
    try {

        //Parse the files with level information
        std::string file;
        if (level == 1) {
            file = Config->getLevel1();
        } else if (level == 2) {
            file = Config->getLevel2();
        } else if (level == 3) {
            file = Config->getLevel3();
        }
        std::ifstream ifstr(file);
        json js = json::parse(ifstr);

        std::vector<std::string> enemies = js["enemies"];
        std::vector<std::string> background = js["Background"];
        for (auto item : enemies) {
            if (item == "car1") {
                world->passingCar = true;
            }
            if (item == "rock") {
                world->rock = true;
            }
            if (item == "car2") {
                world->movingCar = true;
            }
        }
        if (level == 1) {
            Config->setBackground1(background[0]);
            Config->setBackground1Fin(background[1]);
        } else if (level == 2) {
            Config->setBackground2(background[0]);
            Config->setBackground2Fin(background[1]);
        } else if (level == 3) {
            Config->setBackground3(background[0]);
            Config->setBackground3Fin(background[1]);
        }

        world->setCurrentLevel(level);
        world->setBackground(factory->createBackground(level));
        world->setLevelFinished(false);

    } catch (FileError &e) {
        std::cerr << e.what() << e.filePath() << std::endl;
        throw;
    }
}
