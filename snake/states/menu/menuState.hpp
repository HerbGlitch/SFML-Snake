#pragma once

#include "../states.hpp"
#include "../../tools/tools.hpp"
#include "../snake/gameState.hpp"

namespace herbglitch {
    namespace game { struct Data; }

    namespace state {
        class Menu : public State {
        public:
            Menu(game::Data *data);

            void update();
            void render();

        private:
            game::Data *data;

            sf::Sprite background;
            sf::Sprite play;
        };
    }
}