//
// Created by super on 25.05.2023.
//

#include "SplashState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "MainMenuState.hpp"

namespace Donpad {
    SplashState::SplashState(Donpad::GameDataRef data) : _data(data) {

    }

    void SplashState::Init() {
        _data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_PATH);
        _backgroundSprite.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        _backgroundSprite.setOrigin(_backgroundSprite.getTexture()->getSize().x/2,
                                    _backgroundSprite.getTexture()->getSize().y/2);
        _backgroundSprite.setScale(SCREEN_WIDTH/1.f/_backgroundSprite.getTexture()->getSize().x,
                                   SCREEN_HEIGHT/1.f/_backgroundSprite.getTexture()->getSize().y/1.f);
        _backgroundSprite.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    }

    void SplashState::HandleInput() {
        sf::Event event;
        while (_data->window.pollEvent(event))
            if (sf::Event::Closed == event.type)
                _data->window.close();
    }

    void SplashState::Update(float dt) {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
            _data->finalStateMachine.AddState(StateRef(new MainMenuState(_data)), true);
    }

    void SplashState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_backgroundSprite);
        _data->window.display();
    }
}
