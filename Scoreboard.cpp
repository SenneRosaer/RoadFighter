//
// Created by sennerosaer on 8/10/19.
//

#include "Scoreboard.h"
#include "ConfigData.h"
#include "Exception_class/FontLoadError.h"
#include "JSON/single_include/nlohmann/json.hpp"
#include "Singleton/Transformation.h"
#include <fstream>

using json = nlohmann::json;

Scoreboard::Scoreboard(std::shared_ptr<sf::RenderWindow> windowGiven, std::shared_ptr<ConfigData> config)
{
        window = windowGiven;
        Scoreboard::config = config;

        const char* fontfile = config->getFont().c_str();
        try {
                if (!font.loadFromFile(fontfile)) {
                        throw(FontLoadError(fontfile));
                }
        } catch (FileError& e) {
                std::cerr << e.what() << e.filePath() << std::endl;
                throw;
        }
}

void Scoreboard::drawBoard()
{
        std::vector<int> scores2;

        try {

                std::string file = config->getHighscore();
                std::ifstream ifstr(file);
                json js = json::parse(ifstr);

                std::vector<std::string> scores = js["scores"];
                for (auto score : scores) {
                        if (score == "") {
                                scores2.push_back(0);
                        } else {
                                scores2.push_back(std::stoi(score));
                        }
                }

        } catch (FileError& e) {
                std::cerr << e.what() << e.filePath() << std::endl;
                throw;
        }

        std::vector<std::string> names;
        int sum = 0;
        for (auto score : scoresCurrentGame) {
                sum = sum + score;
        }

        for (int i = 0; i < scores2.size(); i++) {
                text[i].setFont(font);
                text[i].setString(std::to_string(scores2[i]));
                if (scores2[i] == sum) {
                        text[i].setColor(sf::Color::Red);
                }
                sf::FloatRect rect = text[i].getLocalBounds();
                text[i].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
                std::pair<double, double> t = Transformation::getInstance(window->getSize().x, window->getSize().y)
                                                  .Transform({0, 1 + (-0.3 * i)});
                text[i].setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
                window->draw(text[i]);
        }
}

void Scoreboard::setScoresCurrentGame(const std::vector<int>& scoresCurrentGame)
{
        Scoreboard::scoresCurrentGame = scoresCurrentGame;
        int sum = 0;
        for (auto item : scoresCurrentGame) {
                sum = sum + item;
        }

        std::string file = config->getHighscore();
        std::ifstream ifstr(file);
        json js = json::parse(ifstr);
        std::vector<std::string> scores = js["scores"];

        std::vector<int> scoreboardScores;
        for (auto score : scores) {
                if (score != "") {
                        scoreboardScores.push_back(std::stoi(score));
                } else {
                        scoreboardScores.push_back(0);
                }
        }
        scoreboardScores.push_back(sum);

        std::sort(scoreboardScores.begin(), scoreboardScores.end(), [](int& a, int& b) -> bool { return a > b; });
        std::vector<std::string> putBack;

        for (int i = 0; i < 5; i++) {
                putBack.push_back(std::to_string(scoreboardScores[i]));
        }

        js["scores"] = putBack;

        std::ofstream out(file);
        out << js << std::endl;
}
