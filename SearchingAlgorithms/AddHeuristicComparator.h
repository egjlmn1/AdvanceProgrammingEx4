//
<<<<<<< HEAD
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
=======
// Created by ophir on 1/29/2020.
//

#ifndef MITKADEM4_ADDHEURISTICCOMPARATOR_H
#define MITKADEM4_ADDHEURISTICCOMPARATOR_H

#include "State.h"

template<class T>
class AddHeuristicComparator {
public:
    bool operator()(State<T> *s1, State<T> *s2) {
        return (s1->GetRouteCost() + s1->GetHeuristic() > s2->GetRouteCost() + s2->GetHeuristic());
    }
};

#endif //MITKADEM4_ADDHEURISTICCOMPARATOR_H
>>>>>>> cf9dd10992fddcb7e0ab2ebbb7f071f020e177d1
