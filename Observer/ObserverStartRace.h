//
// Created by sennerosaer on 8/7/19.
//

#ifndef ROADFIGHTER_OBSERVERSTARTRACE_H
#define ROADFIGHTER_OBSERVERSTARTRACE_H


#include "Observer.h"

class ObserverStartRace : public Observer {
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Font font;
    sf::Text text;

public:
    ObserverStartRace(std::shared_ptr<sf::RenderWindow> wind);

    void update(int timer) override;

    std::string getType() override;


};


#endif //ROADFIGHTER_OBSERVERSTARTRACE_H
