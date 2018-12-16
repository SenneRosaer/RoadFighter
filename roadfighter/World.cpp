//
// Created by senne on 12/15/18.
//

#include "World.h"
#include "EntityFactory.h"

void roadfighter::World::draw() {
    Player->draw();
}

roadfighter::World::World() {
}

void roadfighter::World::setPlayer(const std::shared_ptr<roadfighter::Entity> &Player) {
    World::Player = Player;
}

void roadfighter::World::update() {
    Player->update();
}
