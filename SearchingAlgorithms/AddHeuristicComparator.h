//
// Created by egjlmn1 on 1/30/20.
//

#ifndef FLIGHTSIMULATORMASTER_ADDHEURISTICCOMPARATOR_H
#define FLIGHTSIMULATORMASTER_ADDHEURISTICCOMPARATOR_H

#include "State.h"

template <class T>
class AddHeuristicComparator {
public:
    bool operator()(State<T> *s1, State<T> *s2) {
        return ((s1->GetRouteCost() + s2->GetHeuristic()) > (s2->GetRouteCost() + s2->GetHeuristic()));
    }
};

#endif //FLIGHTSIMULATORMASTER_ADDHEURISTICCOMPARATOR_H
