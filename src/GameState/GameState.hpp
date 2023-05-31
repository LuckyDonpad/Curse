#ifndef TANKS_GAMESTATE_HPP
#define TANKS_GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Player.hpp"
#include "Collision.hpp"
#include "HUD.hpp"

namespace Donpad {
    class GameState : public State{
    public:
        GameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _backgroundSprite;
        Pipe *_pipe;
        sf::Clock _clock;
        Player *_player;
        Collision _collision;
        int _gamestate;
        int _score;
        HUD *_hud;
    };
}


#endif //TANKS_GAMESTATE_HPP
