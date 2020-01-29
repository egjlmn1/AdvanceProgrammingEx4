//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_ISEARCHABLE_H
#define FLIGHTSIMULATORMASTER_ISEARCHABLE_H

#include <vector>
#include "../State.h"

template <class T>
class ISearchable {
public:
    virtual State<T>* GetInitialState() = 0;
    virtual State<T>* GetGoalState() = 0;
    virtual vector<State<T>*> GetAllPossibleStates(State<T>* s) = 0;
};

#endif //FLIGHTSIMULATORMASTER_ISEARCHABLE_H
