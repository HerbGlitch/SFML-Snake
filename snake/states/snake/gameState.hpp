#pragma once

#include "../states.hpp"
#include "../../tools/tools.hpp"
#include "background/background.hpp"
#include "player/player.hpp"

namespace herbglitch {
    namespace game { struct Data; }

    namespace state {
        class Game : public State {
        public:
            Game(game::Data *data);
            ~Game();

            void update();
            void render();

        private:
            game::Data *data;

            snake::Background *background;
            snake::Player *player;
        };
    }
}