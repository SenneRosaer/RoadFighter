//
// Created by sennerosaer on 8/7/19.
//

#ifndef ROADFIGHTER_OBSERVERSTARTRACE_H
#define ROADFIGHTER_OBSERVERSTARTRACE_H

#include "Observer.h"

/**
 * The observer that handles the timer at the start of every level
 */
class ObserverStartRace : public Observer
{
private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Font font;
        sf::Text text;

public:
        /**
         * Constructor with the sfml window
         * @param wind
         */
        ObserverStartRace(std::shared_ptr<sf::RenderWindow> wind);

        /**
         * Updates the observer with the timer
         * @param timer
         */
        void update(int timer) override;

        /**
         * Returns the type of observer
         * @return
         */
        std::string getType() override;
};

#endif // ROADFIGHTER_OBSERVERSTARTRACE_H
