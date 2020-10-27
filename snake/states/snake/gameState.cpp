#include "gameState.hpp"
#include "../../game.hpp"

#include <iostream>

namespace herbglitch {
    namespace state {
        Game::Game(game::Data *data): data(data) {
            background = new snake::Background(data);
            player = new snake::Player(data);
        }

        Game::~Game(){
            delete background;
            delete player;
        }

        void Game::update() {
            background->update();
            player->update();
        }

        void Game::render() {
            background->render();
            player->render();
        }
    }
}