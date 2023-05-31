#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"


namespace Donpad {
    MainMenuState::MainMenuState(Donpad::GameDataRef data) : _data(data) {

    }


    void MainMenuState::Init() {
        // GET BACKGROUND TEXTURE POSITIONED
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_PATH);
        _backGround.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        _backGround.setOrigin(_backGround.getTexture()->getSize().x / 2,
                              _backGround.getTexture()->getSize().y / 2);
        _backGround.setScale(SCREEN_WIDTH / 1.f / _backGround.getTexture()->getSize().x,
                             SCREEN_HEIGHT / 1.f / _backGround.getTexture()->getSize().y / 1.f);
        _backGround.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

        // SET THE PLAY BUTTON
        _data->assets.LoadTexture("Play Button", PLAY_BUTTON_PATH);
        _play_button.setTexture(this->_data->assets.GetTexture("Play Button"));
        _play_button.setPosition((SCREEN_WIDTH / 2) - (_play_button.getGlobalBounds().width / 2),
                                 (SCREEN_WIDTH / 2) - (_play_button.getGlobalBounds().height / 2));
        // SET TITLE
        _data->assets.LoadTexture("Game Title", GAME_TITLE_PATH);
        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
                           _title.getGlobalBounds().height / 2);
    }

    void MainMenuState::HandleInput() {
        sf::Event event;
        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();
            if (_data->inputs.IsSpriteClicked(_play_button, sf::Mouse::Left, _data->window)){
                _data->finalStateMachine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt) {
    }

    void MainMenuState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_backGround);
        _data->window.draw(_title);
        _data->window.draw(_play_button);
        _data->window.display();
    }
}
