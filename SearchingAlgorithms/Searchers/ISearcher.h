//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_ISEARCHER_H
#define FLIGHTSIMULATORMASTER_ISEARCHER_H

#include "../Searchable/ISearchable.h"
#include "../../Solutions/StringSolution.h"

template <class T>
class ISearcher {
    virtual StringSolution search(ISearchable<T> searchable) = 0;
    virtual int GetNumberOfNodesEvaluated() = 0;
};


#endif //FLIGHTSIMULATORMASTER_ISEARCHER_H