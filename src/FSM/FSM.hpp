//
// Created by super on 25.05.2023.
//

#include "State.hpp"
#include <memory>
#include <stack>

namespace Donpad {
    typedef std::unique_ptr<State> StateRef;

    class FSM {
    public:
        FSM() {};
        ~FSM() {};

        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();

        void ProccesStateChanges();


        StateRef &GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}