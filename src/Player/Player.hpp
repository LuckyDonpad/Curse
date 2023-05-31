//
// Created by super on 31.05.2023.
//

#ifndef TANKS_PLAYER_HPP
#define TANKS_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <DEFINITIONS.hpp>
#include "Game.hpp"
#include <vector>


namespace Donpad {
    class Player {
    public:
        Player(GameDataRef data);
        void Draw();
        void Animate(float dt);
        void Update(float dt);
        void Tap();
        const sf::Sprite &GetSprite() ;



    private:
        GameDataRef _data;
        sf::Sprite _playerSprite;
        std::vector<sf::Texture> _animationFrames;
        unsigned _animationIterator;
        sf::Clock _clock;
        sf::Clock _flyClock;

        int _playerState;
        float _velocity;
    };
}

#endif //TANKS_PLAYER_HPP
