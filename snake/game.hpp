#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game {
        struct Data {
            sf::RenderWindow window;
        };
    }

    class Game {
    public:
        Game();
        ~Game();
    
        void Run();

    private:
        game::Data *data;
 
        sf::Clock clock;
    };
}

#endif //GAME_H