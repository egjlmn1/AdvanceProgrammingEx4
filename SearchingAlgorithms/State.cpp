//
// Created by ophir on 1/21/2020.
//

#include "State.h"

template <class T>
State<T>::State(T State) {
    this->state = state;
}

template <class T>
bool State<T>::Equals(State<T> s) {
    return this->state.compare(s.GetState());
}

template <class T>
T State<T>::GetState() {
    return this->state;
}