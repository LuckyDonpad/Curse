//
// Created by super on 25.05.2023.
//

#ifndef TANKS_MAINMENUSTATE_HPP
#define TANKS_MAINMENUSTATE_HPP

#include "State.hpp"
#include "Game.hpp"

namespace Donpad {

    class MainMenuState : public State {
    public:
        MainMenuState(GameDataRef data);

        void Init();

        void HandleInput();

        void Update(float dt);

        void Draw(float dt);

        void Pause() {};

        void Resume() {};
    private:
        GameDataRef _data;
        sf::Sprite _backGround;
        sf::Sprite _title;
        sf::Sprite _play_button;
    };

};

#endif //TANKS_MAINMENUSTATE_HPP
