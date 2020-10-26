#include "gameState.hpp"
#include "../../game.hpp"

#include <iostream>

namespace herbglitch {
    namespace state {
        Game::Game(game::Data *data): data(data) {
            background = new snake::Background(data);
        }

        void Game::update() {
            background->update();
        }

        void Game::render() {
            background->render();
        }
    }
}