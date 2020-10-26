#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace tools {
        inline bool isCollided(sf::Sprite s1, sf::Sprite s2){
            return ((s1.getGlobalBounds().left <= s2.getGlobalBounds().left + s2.getGlobalBounds().width) && 
                    (s1.getGlobalBounds().top  <= s2.getGlobalBounds().top  + s2.getGlobalBounds().height) &&
                    (s2.getGlobalBounds().left <= s1.getGlobalBounds().left + s1.getGlobalBounds().width) && 
                    (s2.getGlobalBounds().top  <= s1.getGlobalBounds().top  + s1.getGlobalBounds().height));
        }

        inline bool isCollided(sf::Vector2f v1, sf::Sprite s1){
            return ((v1.x <= s1.getGlobalBounds().left + s1.getGlobalBounds().width) && 
                    (v1.y <= s1.getGlobalBounds().top + s1.getGlobalBounds().height) && 
                    (v1.x >= s1.getGlobalBounds().width) && 
                    (v1.y >= s1.getGlobalBounds().top));
        }
    }
}