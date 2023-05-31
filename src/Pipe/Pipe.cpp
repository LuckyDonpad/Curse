#include "Pipe.hpp"
#include "DEFINITIONS.hpp"
#include "iostream"

namespace Donpad {
    Pipe::Pipe(GameDataRef data) : _data(data) {
        _landHeight = _data->assets.GetTexture("Pipe Up").getSize().y/3;
        _pipeSpawnYOffset = 0;
    }

    void Pipe::DrawPipes() {
        for (const auto &pipe: pipes)
            _data->window.draw(pipe);
    }

    void Pipe::SpawnBottomPipe() {
        sf::Sprite pipeSprite(_data->assets.GetTexture("Pipe Up"));
        pipeSprite.setPosition(_data->window.getSize().x,
                               _data->window.getSize().y - pipeSprite.getGlobalBounds().height - _pipeSpawnYOffset);
        pipeSprite.setScale(1.f, 1.5f);
        pipes.push_back(pipeSprite);
    }

    void Pipe::SpawnTopPipe() {
        sf::Sprite pipeSprite(_data->assets.GetTexture("Pipe Down"));
        pipeSprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
        pipeSprite.setScale(1.f, 1.5f);
        pipes.push_back(pipeSprite);
    }

    void Pipe::SpawnScoringSector() {
        sf::Sprite pipeSprite(_data->assets.GetTexture("Pipe Down"));
        pipeSprite.setPosition(_data->window.getSize().x, 0);
        pipeSprite.setScale(0.1f, 40.f);
        _scoringSectors.push_back(pipeSprite);
    }

    void Pipe::MovePipes(float dt) {
        for (int i = 0; i < pipes.size(); ++i) {
            auto &pipe = pipes.at(i);
            if (pipe.getPosition().x < -pipe.getGlobalBounds().width)
                pipes.erase(pipes.begin() + i);
            else {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                pipe.move(-movement, 0);
            }
        }
    }

    void Pipe::MoveScoringSectors(float dt) {
        for (int i = 0; i < _scoringSectors.size(); ++i) {
            auto &pipe = _scoringSectors.at(i);
            if (pipe.getPosition().x < -pipe.getGlobalBounds().width)
                _scoringSectors.erase(_scoringSectors.begin() + i);
            else {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                pipe.move(-movement, 0);
            }
        }
    }

    void Pipe::RandomisePipeOffset() {
        _pipeSpawnYOffset = rand() % (_landHeight);
    }

    std::vector<sf::Sprite> Pipe::GetPipes(){
        return pipes;
    }


    std::vector<sf::Sprite> &Pipe::GetScoringSprites() {
        return _scoringSectors;
    }

    void Pipe::killScoringSector(int i) {
        _scoringSectors.erase(_scoringSectors.begin()+i);
    }

}
