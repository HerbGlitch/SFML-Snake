#pragma once

#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game { struct Data; }

    namespace snake {
        class Background {
        public:
            Background(game::Data *data);
            ~Background();

            void update();
            void render();

        private:
            game::Data *data;

            std::vector<sf::Sprite> tiles;
        };
    }
}