#include "background.hpp"
#include "../../../game.hpp"

namespace herbglitch {
    namespace snake {
        Background::Background(game::Data *data): data(data){
            tiles.push_back(sf::Sprite(data->texture.getTexture("background_tile")));
            tiles.push_back(sf::Sprite(data->texture.getTexture("background_tile")));
            tiles.at(0).setScale(sf::Vector2f(0.2, 0.2));
            tiles.at(1).setScale(sf::Vector2f(0.2, 0.2));
            tiles.at(1).setColor(sf::Color::Red);
            tiles.at(1).setPosition(tiles.at(0).getGlobalBounds().width, 0);
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