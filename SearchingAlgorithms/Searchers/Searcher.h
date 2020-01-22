//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_SEARCHER_H
#define FLIGHTSIMULATORMASTER_SEARCHER_H

#include "ISearcher.h"
#include "../State.h"
#include "../MyPriorityQueue.h"
#include "../../Solutions/StringSolution.h"

template <class T>
class Searcher : ISearcher<T> {
private:
    MyPriorityQueue<State<T>> openList;
    int evaluatedNodes;

public:
    Searcher<T>();
    State<T> PopOpenList();
    int OpenListSize();
    int GetNumberOfNodesEvaluated();
    virtual StringSolution search(ISearchable<T> searchable) = 0;
};

#endif //FLIGHTSIMULATORMASTER_SEARCHER_H
