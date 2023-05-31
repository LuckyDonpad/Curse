#ifndef TANKS_PIPE_HPP
#define TANKS_PIPE_HPP

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "vector"

namespace Donpad {


    class Pipe {
    public:
        Pipe(GameDataRef data);
        void DrawPipes();
        void SpawnBottomPipe();
        void SpawnTopPipe();
        void SpawnScoringSector();
        void MovePipes( float dt);
        void RandomisePipeOffset();
        std::vector<sf::Sprite> GetPipes();
        std::vector<sf::Sprite> &GetScoringSprites();
        void MoveScoringSectors(float dt);
        void killScoringSector(int i);
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipes;
        std::vector<sf::Sprite> _scoringSectors;
        int _landHeight;
        int _pipeSpawnYOffset;

    };
}

#endif //TANKS_PIPE_HPP
