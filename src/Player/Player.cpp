//
// Created by super on 31.05.2023.
//

#include "Player.hpp"
#include "cmath"

namespace Donpad {
    Player::Player(GameDataRef data) : _data(data) {
        _animationIterator = 0;
        _animationFrames.push_back(_data->assets.GetTexture("Player Frame 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Player Frame 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Player Frame 3"));
        _animationFrames.push_back(_data->assets.GetTexture("Player Frame 4"));
        _animationFrames.push_back(_data->assets.GetTexture("Player Frame 5"));
        _animationFrames.push_back(_data->assets.GetTexture("Player Frame 6"));
        _playerSprite.setTexture(_animationFrames.at(_animationIterator));
        _playerSprite.setScale(0.25f, 0.25f);
        _playerSprite.setPosition(_data->window.getSize().x / 4 - (_playerSprite.getGlobalBounds().width / 2),
                                  _data->window.getSize().y / 2 - (_playerSprite.getGlobalBounds().height / 2));
        _playerSprite.setOrigin(
                (_data->assets.GetTexture("Player Frame 1").getSize().x * _playerSprite.getScale().x) / 2.f,
                (_data->assets.GetTexture("Player Frame 1").getSize().y * _playerSprite.getScale().y) / 2.f);
        _playerState = PLAYER_STATE_STILL;
        _velocity = 1.f;
    }

    void Player::Update(float dt) {
        if (_playerState == PLAYER_STATE_FALLING) {
            _playerSprite.move(0, GRAVITY * dt + pow(_velocity * dt, 2) / 2);
            _playerSprite.rotate(2.8 * dt);
        } else if (_playerState == PLAYER_STATE_FLYING) {
            _playerSprite.move(0, -FLY_SPEED * dt + pow(_velocity * dt, 2) / 2);
            _playerSprite.rotate(-2.8 * dt);
        }
        _velocity += 8 * dt;
        if (_playerState == PLAYER_STATE_FLYING & _flyClock.getElapsedTime().asSeconds() > FLY_DURATION) {
            _flyClock.restart();
            _playerState = PLAYER_STATE_FALLING;
        }
    }

    void Player::Tap() {
        _playerSprite.setRotation(0);
        _velocity = 10;
        _flyClock.restart();
        _playerState = PLAYER_STATE_FLYING;
    }

    void Player::Draw() {
        _playerSprite.setTexture(_animationFrames.at(_animationIterator));
        _playerSprite.setScale(0.2f, 0.2f);
        _data->window.draw(_playerSprite);
    }

    void Player::Animate(float dt) {
        if (_clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / _animationFrames.size()) {
            _animationIterator = (_animationIterator + 1) % _animationFrames.size();
            _clock.restart();
        }
    }

    const sf::Sprite &Player::GetSprite() {
        return _playerSprite;
    }

}