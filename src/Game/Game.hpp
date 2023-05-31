//
// Created by super on 25.05.2023.
//

#ifndef TANKS_GAME_HPP
#define TANKS_GAME_HPP
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "FSM.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Donpad {
    struct GameData{
        FSM finalStateMachine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager inputs;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f/60.f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<GameData>();
        void Run();
    };
}

#endif //TANKS_GAME_HPP
