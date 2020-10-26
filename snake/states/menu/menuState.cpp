#include "menuState.hpp"
#include "../../game.hpp"

#include <iostream>

namespace herbglitch {
    namespace state {
        Menu::Menu(game::Data *data) : data(data) {
            background.setTexture(data->texture.getTexture("background"));
            play.setTexture(data->texture.getTexture("play_btn"));
            background.setPosition(0, 0);
            tools::centerOrigin(play);
            play.setPosition(1920.0f / 2.0f, 1080.0f / 2.0f);
        }

        void Menu::update() {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                data->handler->AddState(new state::Game(data));
            }
        }

        void Menu::render() {
            data->window.draw(background);
            data->window.draw(play);
        }
    }
}