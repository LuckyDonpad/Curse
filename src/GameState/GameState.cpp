//
// Created by super on 25.05.2023.
//

#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "Player.hpp"
#include "GameOverState.hpp"
#include "iostream"
#include "HUD.hpp"

namespace Donpad {
    GameState::GameState(GameDataRef data) : _data(data) {

    }

    void GameState::Init() {
        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_PATH);
        _backgroundSprite.setTexture(this->_data->assets.GetTexture("Game Background"));
        _backgroundSprite.setScale(SCREEN_WIDTH / 1.f / _backgroundSprite.getTexture()->getSize().x,
                                   SCREEN_HEIGHT / 1.f / _backgroundSprite.getTexture()->getSize().y / 1.f);
        _backgroundSprite.setPosition(0, 0);

        _data->assets.LoadTexture("Pipe Up", PIPE_UP_PATH);
        _data->assets.LoadTexture("Pipe Down", PIPE_DOWN_PATH);

        _pipe = new Pipe(_data);

        _data->assets.LoadTexture("Player Frame 1", PLAYER_FRAME_1);
        _data->assets.LoadTexture("Player Frame 2", PLAYER_FRAME_2);
        _data->assets.LoadTexture("Player Frame 3", PLAYER_FRAME_3);
        _data->assets.LoadTexture("Player Frame 4", PLAYER_FRAME_4);
        _data->assets.LoadTexture("Player Frame 5", PLAYER_FRAME_5);
        _data->assets.LoadTexture("Player Frame 6", PLAYER_FRAME_6);

        _player = new Player(_data);
        _score = 0;
        _gamestate = GameStates::eReady;

        _data->assets.LoadFont("Score", FONT_PATH);
        _hud = new HUD(_data);
        _score = 0;
        _hud->UpdateScore(_score);
    }

    void GameState::HandleInput() {
        sf::Event event;
        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();
            if (_data->inputs.IsSpriteClicked(_backgroundSprite, sf::Mouse::Left, _data->window)) {
                if (_gamestate != GameStates::eGameOver) {
                    _gamestate = GameStates::ePlaying;
                    _player->Tap();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                _gamestate = GameStates::eReady;
            }
        }
    }

    void GameState::Update(float dt) {
        if (_gamestate != GameStates::eGameOver) {
            _player->Animate(dt);
            _pipe->MovePipes(dt);
            _pipe->MoveScoringSectors(dt);
        }
        if (_gamestate == GameStates::ePlaying) {
            if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_CLOCK) {
                _pipe->RandomisePipeOffset();
                _pipe->SpawnBottomPipe();
                _pipe->SpawnScoringSector();
                _pipe->SpawnTopPipe();
                _clock.restart();
            }

            _player->Update(dt);

            if (_collision.CheckLowerBorderCollision(_player->GetSprite()))
                _gamestate = GameStates::eGameOver;
            std::vector<sf::Sprite> pipes = _pipe->GetPipes();
            for (auto &pipe: pipes) {
                if (_collision.CheckSpriteCollision(_player->GetSprite(), pipe)) {
                    _gamestate = GameStates::eGameOver;
                    break;
                }
            }
            for (auto &scoreSector: _pipe->GetScoringSprites()) {
                if (_collision.CheckSpriteCollision(_player->GetSprite(), scoreSector)) {
                    _score += 1;
                    _hud->UpdateScore(_score);
                    _pipe->killScoringSector(0);
                }
            }
            if (_gamestate == GameStates::eGameOver)
                _data->finalStateMachine.AddState(StateRef(new GameOverState(_data, _score)), true);

        }
    }

    void GameState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_backgroundSprite);
        _pipe->DrawPipes();
        _player->Draw();
        _hud->Draw();
        _data->window.display();
    }
}