//
// Created by sennerosaer on 8/7/19.
//

#include "ObserverStartRace.h"
#include "../Singleton/Transformation.h"


ObserverStartRace::ObserverStartRace(std::shared_ptr<sf::RenderWindow> wind) {
    this->window = wind;
    if (!font.loadFromFile("../Observer/arial.ttf")) {
        std::cout << "cant load font" << std::endl;
    }
    text.setFont(font);
    // text.setFillColor(sf::Color::White);
    text.setCharacterSize(30);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);

}

void ObserverStartRace::update(int timer) {
    if(timer != 0) {
        text.setString(std::to_string(timer));
        std::pair<double, double> t =
                Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({-0.9, -2});
        text.setPosition(static_cast<float>(t.first), static_cast<float>(t.second));
        window->draw(text);
    }

}

std::string ObserverStartRace::getType() {
    return "StartRaceTimer";
}
