#pragma once
#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace handler {
        template <class State>
        class Game {
        public:
            Game();
            ~Game();

            void update();
            void render();

            void AddState();
            void RemoveState();
            void PauseState();
        private:
            std::map<std::string, State *> states;
        };
    }
}