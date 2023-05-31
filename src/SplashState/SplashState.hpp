//
// Created by super on 25.05.2023.
//

#ifndef TANKS_SPLASHSTATE_HPP
#define TANKS_SPLASHSTATE_HPP
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Donpad {


    class SplashState : public State{
    public:
        SplashState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _backgroundSprite;
    };
}

#endif //TANKS_SPLASHSTATE_HPP
