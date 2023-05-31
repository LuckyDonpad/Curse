//
// Created by super on 01.06.2023.
//

#ifndef TANKS_HUD_HPP
#define TANKS_HUD_HPP
#include "Game.hpp"
namespace Donpad {

    class HUD {

    public:
        HUD(GameDataRef data);

        void Draw();
        void UpdateScore(int i);
    private:
        GameDataRef _data;
        sf::Text _scoreText;


    };

}
#endif //TANKS_HUD_HPP
