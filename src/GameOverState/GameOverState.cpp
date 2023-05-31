#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

namespace Donpad {
    GameOverState::GameOverState(Donpad::GameDataRef data, int score) : _data(data) {
        _score = score;
    }

    void GameOverState::Init() {
        _data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_PATH);
        _backgroundSprite.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _backgroundSprite.setOrigin(_backgroundSprite.getTexture()->getSize().x/2,
                                    _backgroundSprite.getTexture()->getSize().y/2);
        _backgroundSprite.setScale(SCREEN_WIDTH/1.f/_backgroundSprite.getTexture()->getSize().x,
                                   SCREEN_HEIGHT/1.f/_backgroundSprite.getTexture()->getSize().y/1.f);
        _backgroundSprite.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

        _scoreText.setFont(_data->assets.GetFont("Score"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize(64);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 8);
    }

    void GameOverState::HandleInput() {
        sf::Event event;
        while (_data->window.pollEvent(event))
            if (sf::Event::Closed == event.type)
                _data->window.close();
    }

    void GameOverState::Update(float dt) {
    }

    void GameOverState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_backgroundSprite);
        _data->window.draw( _scoreText);
        _data->window.display();
    }
}