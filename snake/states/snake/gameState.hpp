#pragma once

#include "../states.hpp"
#include "../../tools/tools.hpp"
#include "background/background.hpp"

namespace herbglitch {
    namespace game { struct Data; }

    namespace state {
        class Game : public State {
        public:
            Game(game::Data *data);

            void update();
            void render();

        private:
            game::Data *data;

            snake::Background *background;
        };
    }
}