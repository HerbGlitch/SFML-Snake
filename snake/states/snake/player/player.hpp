#pragma once

#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game { struct Data; }

    namespace snake {
        enum class Rotation { UP, LEFT, RIGHT, DOWN };

        class Player {
        public:
            Player(game::Data *data);
            ~Player();

            void update();
            void render();

        private:
            void GetKeyPress();
            void Rotate();
            bool AnimateRotation();
            bool CanRotate();
            void Move();

            game::Data *data;

            sf::Sprite head;
            std::vector<sf::Sprite> body;

            Rotation rotation = Rotation::UP;
            Rotation previous = Rotation::UP;

            float playerSpeed = 5.0f;
            float currRotation = 0.0f;
            float nextRotation = 0.0f;
            bool rotating = false;
        };
    }
}