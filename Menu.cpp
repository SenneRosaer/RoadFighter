//
// Created by sennerosaer on 7/22/19.
//

#include "Menu.h"
#include "Singleton/Transformation.h"
#include "Exception_class/FontLoadError.h"
#include "ConfigData.h"

Menu::Menu(std::shared_ptr<sf::RenderWindow> windowGiven, std::shared_ptr<ConfigData> config) {
    window = windowGiven;
    Menu::config = config;

    try {
        std::string fontfile = config->getFont();
        if (!font.loadFromFile(fontfile)) {
            throw (FontLoadError(fontfile.c_str()));
        }
    } catch (FileError &e) {
        std::cerr << e.what() << e.filePath()<<  std::endl;
        throw;
    }

    //constructs all the text used for the levels
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Level 1");
    sf::FloatRect rect = text[0].getLocalBounds();
    text[0].setOrigin(rect.left + rect.width / 2.0f,
                      rect.top + rect.height / 2.0f);
    std::pair<double, double> t =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({0, 0});
    text[0].setPosition(static_cast<float>(t.first), static_cast<float>(t.second));


    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Level 2");
    sf::FloatRect rect2 = text[1].getLocalBounds();
    text[1].setOrigin(rect2.left + rect2.width / 2.0f,
                      rect2.top + rect2.height / 2.0f);
    std::pair<double, double> t2 =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({0, -0.4});
    text[1].setPosition(static_cast<float>(t2.first), static_cast<float>(t2.second));


    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Level 3");
    sf::FloatRect rect3 = text[2].getLocalBounds();
    text[2].setOrigin(rect3.left + rect3.width / 2.0f,
                      rect3.top + rect3.height / 2.0f);
    std::pair<double, double> t3 =
            Transformation::getInstance(window->getSize().x, window->getSize().y).Transform({0, -0.8});
    text[2].setPosition(static_cast<float>(t3.first), static_cast<float>(t3.second));
}

void Menu::drawMenu() {
    for (int i = 0; i < 3; i++) {
        window->draw(text[i]);

    }

}

void Menu::Up() {
    //Colors the level above if there is one red
    if (selected - 1 >= 0) {
        text[selected].setColor(sf::Color::White);
        text[selected - 1].setColor(sf::Color::Red);
        selected--;
    }

}

void Menu::Down() {
    //Colors the level below if there is one red
    if (selected + 1 <= 2) {
        text[selected].setColor(sf::Color::White);
        text[selected + 1].setColor(sf::Color::Red);
        selected++;
    }
}


int Menu::GetSelected() {
    return selected + 1;
}
