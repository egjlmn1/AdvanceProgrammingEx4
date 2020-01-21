//
// Created by ophir on 1/21/2020.
//

#include "State.h"

State::State(string State) {
    this->state = state;
}

bool State::Equals(State s) {
    return this->state.compare(s.GetState());
}

string State::GetState() {
    return this->state;
}