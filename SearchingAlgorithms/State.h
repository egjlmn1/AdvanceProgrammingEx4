//
// Created by ophir on 1/21/2020.
//

#ifndef FLIGHTSIMULATORMASTER_STATE_H
#define FLIGHTSIMULATORMASTER_STATE_H

#include <string>

using namespace std;

template <class T>
class State {
private:
    T state;
    double cost;
    double routeCost;
    double heuristic;
    State<T>* cameFrom;
public:
    State(T state, double cost, double heuristic);
    virtual bool Equals(State<T>* s);
    T GetState();
    double GetCost();
    State<T>* GetPrevious();
    void UpdateCost(double newCost);
    void UpdatePrevious(State<T>* prev);
    double GetHeuristic();
    void UpdateRouteCost(double c);
    double GetRouteCost();
};

template<class T>
State<T>::State(T state, double cost, double heuristic) {
    this->state = state;
    this->cost = cost;
    this->heuristic = heuristic;
    this->cameFrom = NULL;
    this->routeCost = INT32_MAX;
}

template<class T>
bool State<T>::Equals(State<T> *s) {
    return !this->state.compare(s->GetState());
}

template<class T>
T State<T>::GetState() {
    return this->state;
}

template<class T>
double State<T>::GetCost() {
    return this->cost;
}

template<class T>
State<T> *State<T>::GetPrevious() {
    return this->cameFrom;
}

template<class T>
void State<T>::UpdateCost(double newCost) {
    this->cost = newCost;
}

template<class T>
void State<T>::UpdatePrevious(State<T> *prev) {
    this->cameFrom = prev;
}

template<class T>
double State<T>::GetHeuristic() {
    return this->heuristic;
}

template<class T>
void State<T>::UpdateRouteCost(double newRouteCost) {
    this->routeCost = newRouteCost;
}

template<class T>
double State<T>::GetRouteCost() {
    return this->routeCost;
}

#endif //FLIGHTSIMULATORMASTER_STATE_H
