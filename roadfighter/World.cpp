//
// Created by senne on 12/15/18.
//

#include "World.h"
#include "EntityFactory.h"

void roadfighter::World::draw() {
    Background->draw();
    Player->draw();

}

roadfighter::World::World() {
}

void roadfighter::World::setPlayer(const std::shared_ptr<roadfighter::Entity> &Player) {
    World::Player = Player;
}

void roadfighter::World::update() {
    Player->update();
    Background->update();
}

void roadfighter::World::setBackground(const std::shared_ptr<roadfighter::Entity> &Background) {
    World::Background = Background;
}
