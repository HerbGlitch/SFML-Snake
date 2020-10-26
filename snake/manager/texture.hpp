#ifndef TEXTURE_H
#define TEXTURE_H
#include <SFML/Graphics.hpp>
#include <iostream>

namespace herbglitch {
    namespace manager {
        class Texture {
        public:
            Texture();
            ~Texture();

            void load(std::string filepath, std::string name);

            sf::Texture* &getTexture(std::string name);
            std::map<std::string, sf::Texture*> &getTextures();

        private:
            std::map<std::string, sf::Texture*> textures;
        };
    }
}

#endif // TEXTURE_H