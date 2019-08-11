//
// Created by sennerosaer on 8/10/19.
//

#include <fstream>
#include "Scoreboard.h"
#include "Exception_class/FontLoadError.h"
#include "Singleton/Transformation.h"
#include "JSON/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

Scoreboard::Scoreboard(std::shared_ptr<sf::RenderWindow> windowGiven) {
    window = windowGiven;

    try {
        if (!font.loadFromFile("../Observer/arial.ttf")) {
            throw (FontLoadError("../Observer/arial.ttf"));
        }
    } catch (FileError &e) {
        std::cerr << e.what() << e.filePath()<<  std::endl;
        throw;
    }

    //TODO calcScores and update
}

void Scoreboard::drawBoard() {
    std::vector<int> scores2;

    try {


        std::string file = "../JSON/HighScore.json";
        std::cout << file << std::endl;
        std::ifstream ifstr(file);
        json js = json::parse(ifstr);

        std::vector<std::string> scores = js["scores"];
        for(auto score: scores){
            if(score == ""){
                scores2.push_back(0);
            } else {
                scores2.push_back(std::stoi(score));
            }
        }


    } catch (FileError &e) {
        std::cerr << e.what() << e.filePath() << std::endl;
        throw;
    }


    std::vector<std::string> names;

    for (int i = 0; i < scores2.size(); i++) {
        text[i].setFont(font);
        //TODO namen
        text[i].setString( std::to_string(scores2[i]));
        sf::FloatRect rect = text[i].getLocalBounds();
        text[i].setOrigin(rect.left + rect.width / 2.0f,
                          rect.top + rect.height / 2.0f);
        std::pair<double, double> t =
                Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({0, 1 + (-0.3*i)});
        text[i].setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
        window->draw(text[i]);
    }

}

void Scoreboard::setScoresCurrentGame(const std::vector<int> &scoresCurrentGame) {
    Scoreboard::scoresCurrentGame = scoresCurrentGame;
    int sum = 0;
    for(auto item : scoresCurrentGame){
        sum = sum + item;
    }

    std::string file = "../JSON/HighScore.json";
    std::ifstream ifstr(file);
    json js = json::parse(ifstr);
    std::vector<std::string> scores = js["scores"];

    std::vector<int> scoreboardScores;
    for(auto score: scores){
        if(score != "") {
            scoreboardScores.push_back(std::stoi(score));
        } else {
            scoreboardScores.push_back(0);
        }
    }
    scoreboardScores.push_back(sum);

    std::sort(scoreboardScores.begin(),scoreboardScores.end(),[](int& a, int& b) -> bool {
        return a > b ;
    });
    std::vector<std::string> putBack;

    for (int i = 0; i < 5; i++) {
        putBack.push_back(std::to_string(scoreboardScores[i]));

    }

    js["scores"] = putBack;

    std::ofstream out ("../JSON/HighScore.json");
    out << js << std::endl;

}
