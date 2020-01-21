//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_ISEARCHER_H
#define FLIGHTSIMULATORMASTER_ISEARCHER_H

#include "../Searchable/ISearchable.h"

template <class T>
class ISearcher {
    //virtual Solution search(ISearchable searchable) = 0;
    virtual string search(ISearchable<T> searchable) = 0;
    virtual int GetNumberOfNodesEvaluated() = 0;
};


#endif //FLIGHTSIMULATORMASTER_ISEARCHER_H
