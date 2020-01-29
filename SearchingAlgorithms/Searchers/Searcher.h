//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_SEARCHER_H
#define FLIGHTSIMULATORMASTER_SEARCHER_H

#include "ISearcher.h"
#include "../State.h"
#include "../MyPriorityQueue.h"
#include "../../Solutions/Solution.h"

template <class T, class Solution>
class Searcher : ISearcher<T> {
private:
    MyPriorityQueue<State<T>> openList;
    int evaluatedNodes;

public:
    Searcher<T>();
    void PushOpenList(State<T>* s);
    State<T> PopOpenList();
    bool IsInOpenList(State<T>* state);
    int OpenListSize();
    int GetNumberOfNodesEvaluated();
    void UpdateQueue();
    virtual Solution search(ISearchable<T> searchable) = 0;
};

#endif //FLIGHTSIMULATORMASTER_SEARCHER_H
