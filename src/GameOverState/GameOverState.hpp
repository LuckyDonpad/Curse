#ifndef TANKS_GAMEOVERSTATE_HPP
#define TANKS_GAMEOVERSTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Donpad {
    class GameOverState : public State{
    public:
        GameOverState(GameDataRef data, int score);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _backgroundSprite;
        sf::Text _scoreText;
        int _score;
    };
}


#endif //TANKS_GAMEOVERSTATE_HPP
