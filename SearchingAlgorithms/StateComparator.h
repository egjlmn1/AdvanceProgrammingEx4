//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_STATECOMPARATOR_H
#define FLIGHTSIMULATORMASTER_STATECOMPARATOR_H

#include "State.h"

template <class T>
class StateComparator {
public:
    bool operator()(State<T>* s1, State<T>* s2);
};

#endif //FLIGHTSIMULATORMASTER_STATECOMPARATOR_H