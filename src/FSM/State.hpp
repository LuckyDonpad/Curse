//
// Created by super on 25.05.2023.
//

#ifndef TANKS_STATE_HPP
#define TANKS_STATE_HPP

namespace Donpad {
    class State {
    public:
        virtual void Init() = 0;

        virtual void HandleInput() = 0;

        virtual void Update(float dt) = 0;

        virtual void Draw(float delta) = 0;

        virtual void Pause() {}

        virtual void Resume() {}
    };
}

#endif //TANKS_STATE_HPP
