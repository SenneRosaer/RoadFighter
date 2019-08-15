//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_SCOREBOARD_H
#define ROADFIGHTER_SCOREBOARD_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "iostream"
class ConfigData;

/**
 * Handles the scoreboard at the end of the game
 */
class Scoreboard {
private:
    /**
     * Game window
     */
    std::shared_ptr<sf::RenderWindow> window;

    /**
     * Scores for the levels played in the current game
     */
    std::vector<int> scoresCurrentGame;

    /**
     * configuration data
     */
    std::shared_ptr<ConfigData> config;
public:
    /**
     * Constructor with sfml window and configuration data
     * @param window
     * @param config
     */
    Scoreboard(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<ConfigData> config);

    /**
     * Drawing the scoreboard with the scores specified in the highscore file
     */
    void drawBoard();

    /**
     * Calculate the total score of the current game and updates the highscore file correspondingly
     * @param scoresCurrentGame
     */
    void setScoresCurrentGame(const std::vector<int> &scoresCurrentGame);


private:
    /**
     * font used
     */
    sf::Font font;

    /**
     * text for the 5 top scores
     */
    sf::Text text[5];
};


#endif //ROADFIGHTER_SCOREBOARD_H
