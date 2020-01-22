//
// Created by ophir on 1/21/2020.
//

#include "State.h"

template <class T>
State<T>::State(T State, double cost) {
    this->state = state;
}

template <class T>
bool State<T>::Equals(State<T>* s) {
    return this->state.compare(s->GetState());
}

template <class T>
T State<T>::GetState() {
    return this->state;
}

template <class T>
double State<T>::GetCost() {
    return this->cost;
}

template <class T>
State<T>* State<T>::GetPrevious() {
    return this->cameFrom;
}

template <class T>
void State<T>::UpdateCost(double newCost) {
    this->cost = newCost;
}

template <class T>
void State<T>::UpdatePrevious(State<T> *prev) {
    this->cameFrom = prev;
}