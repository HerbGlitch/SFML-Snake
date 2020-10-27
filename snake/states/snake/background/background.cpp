#include "background.hpp"
#include "../../../game.hpp"

namespace herbglitch {
    namespace snake {
        Background::Background(game::Data *data): data(data){
            int height = 99;
            int width = 99;
            float scale = 0.15f;
            bool toggle = false;
            for(int y = 0; y < height; y++){
                for(int x = 0; x < width; x++){
                    if(toggle){ tiles.push_back(sf::Sprite(data->texture.getTexture("background_tile"))); }
                    else { tiles.push_back(sf::Sprite(data->texture.getTexture("background_tile_01"))); }
                    tiles.at((y * width) + x).setScale(scale, scale);
                    tiles.at((y * width) + x).setPosition(tiles.at(0).getGlobalBounds().width * x, tiles.at(0).getGlobalBounds().height * y);
                    toggle = !toggle;
                }
            }
        }

        Background::~Background(){}

        void Background::update(){}

        void Background::render(){
            for(sf::Sprite &tile : tiles){
                data->window.draw(tile);
            }
        }
    }
}