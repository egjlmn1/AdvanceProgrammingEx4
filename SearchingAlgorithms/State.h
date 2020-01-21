//
// Created by ophir on 1/21/2020.
//

#ifndef FLIGHTSIMULATORMASTER_STATE_H
#define FLIGHTSIMULATORMASTER_STATE_H

#include <string>

using namespace std;

class State {
private:
    string state;
    double cost;
    State* cameFrom;

public:
    State(string State);
    virtual bool Equals(State s);
    string GetState();
};


#endif //FLIGHTSIMULATORMASTER_STATE_H
