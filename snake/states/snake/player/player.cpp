#include "player.hpp"
#include "../../../game.hpp"

namespace herbglitch {
    namespace snake {
        Player::Player(game::Data *data): data(data){
            float scale = 0.15f;

            head.setTexture(data->texture.getTexture("snake_head"));
            head.setOrigin(head.getGlobalBounds().width / 2.0f, head.getGlobalBounds().height);
            head.setScale(scale, scale);
            head.setPosition(head.getGlobalBounds().width / 2.0f, 1080);
        }

        Player::~Player(){

        }

        void Player::update(){
            GetKeyPress();
            if(!rotating){
                Rotate();
                rotating = CanRotate();
            }

            if(rotating){
                rotating = AnimateRotation();
            }

            Move();
        }

        void Player::render(){
            data->window.draw(head);
        }

        void Player::GetKeyPress(){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { rotation = Rotation::DOWN; }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { rotation = Rotation::UP; }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { rotation = Rotation::LEFT; }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { rotation = Rotation::RIGHT; }
        }

        void Player::Rotate(){
            switch(rotation) {
                case Rotation::UP:
                    if(previous == Rotation::LEFT){ nextRotation = 90.0f; }
                    if(previous == Rotation::RIGHT){ nextRotation = -90.0f; }
                    break;
                case Rotation::LEFT:
                    if(previous == Rotation::DOWN){ nextRotation = 90.0f; }
                    if(previous == Rotation::UP){ nextRotation = -90.0f; }
                    break;
                case Rotation::DOWN:
                    if(previous == Rotation::RIGHT){ nextRotation = 90.0f; }
                    if(previous == Rotation::LEFT){ nextRotation = -90.0f; }
                    break;
                case Rotation::RIGHT:
                    if(previous == Rotation::UP){ nextRotation = 90.0f; }
                    if(previous == Rotation::DOWN){ nextRotation = -90.0f; }
                    break;
            }
        }
        
        bool Player::AnimateRotation(){
            float rotationSpeed = nextRotation; // / ((75.0f / 2.0f) / playerSpeed);

            if(nextRotation != 0.0f){
                if(nextRotation > 0){ rotationSpeed = (nextRotation - currRotation <= rotationSpeed)? nextRotation - currRotation : rotationSpeed; }
                if(nextRotation < 0){ rotationSpeed = (nextRotation + currRotation >= -rotationSpeed)? nextRotation + currRotation : -rotationSpeed; }
                if(nextRotation != currRotation) {
                    currRotation += rotationSpeed;
                    head.rotate(rotationSpeed);
                    return true;
                }
                nextRotation = 0.0;
                currRotation = 0.0;
                previous = rotation;
            }

            return false;
        }

        bool Player::CanRotate(){
            std::cout << "top: " << (int)head.getPosition().y % (int)head.getGlobalBounds().width << "  left:" << (int)head.getPosition().x % (int)(head.getGlobalBounds().width / 2.0f) << std::endl;
            return ((nextRotation != 0) &&
                   (((int)head.getPosition().y % (int)(head.getGlobalBounds().height + (head.getGlobalBounds().height / 2.0f))) == 0) &&
                   (((int)head.getPosition().x % (int)(head.getGlobalBounds().width / 2.0f)) == 0));
        }

        void Player::Move(){
            switch(previous){
                case Rotation::UP:
                    head.move(0, -playerSpeed);
                    break;
                case Rotation::LEFT:
                    head.move(-playerSpeed, 0);
                    break;
                case Rotation::DOWN:
                    head.move(0, playerSpeed);
                    break;
                case Rotation::RIGHT:
                    head.move(playerSpeed, 0);
                    break;
            }
        }
    }
}