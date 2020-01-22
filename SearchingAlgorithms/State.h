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
    State<T>* cameFrom;

public:
    State<T>(T state, double cost);
    virtual bool Equals(State<T>* s);
    T GetState();
    double GetCost();
    State<T>* GetPrevious();
    void UpdateCost(double newCost);
    void UpdatePrevious(State<T>* prev);
};


#endif //FLIGHTSIMULATORMASTER_STATE_H
