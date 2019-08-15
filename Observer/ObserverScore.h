//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_OBSERVERSCORE_H
#define ROADFIGHTER_OBSERVERSCORE_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

/**
 * The observer that handles the score
 */
class ObserverScore : public Observer {
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Font font;
    sf::Text text;

public:
    /**
     * Constructor with sfml window
     * @param wind
     */
    ObserverScore(std::shared_ptr<sf::RenderWindow> wind);

    /**
     * Updates the score
     * @param score
     */
    void update(int score) override;

    /**
     * Returns the type of the observer
     * @return
     */
    std::string getType() override;
};

#endif // ROADFIGHTER_OBSERVERSCORE_H
