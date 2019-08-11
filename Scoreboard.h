//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_SCOREBOARD_H
#define ROADFIGHTER_SCOREBOARD_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "iostream"


class Scoreboard {
private:
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<int> scoresCurrentGame;
public:
    Scoreboard(std::shared_ptr<sf::RenderWindow> window);
    void drawBoard();

    void setScoresCurrentGame(const std::vector<int> &scoresCurrentGame);


private:
    int selected = 0;
    sf::Font font;
    sf::Text text[5];
};


#endif //ROADFIGHTER_SCOREBOARD_H
