//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_SEARCHER_H
#define FLIGHTSIMULATORMASTER_SEARCHER_H

#include "ISearcher.h"
#include "../State.h"
#include "../MyPriorityQueue.h"

template<class T, class Solution, class Comparator>
class Searcher : public ISearcher<T, Solution> {
private:
    MyPriorityQueue<T, Comparator> openList;
    int evaluatedNodes;

public:
    Searcher<T, Solution, Comparator>();
    void PushOpenList(State<T>* s);

    State<T> *PopOpenList();
    bool IsInOpenList(State<T>* state);
    int OpenListSize();
    int GetNumberOfNodesEvaluated();
    void UpdateQueue();
    virtual Solution search(ISearchable<T> *searchable) = 0;
};


template<class T, class Solution, class Comparator>
Searcher<T, Solution, Comparator>::Searcher() {
    this->openList = MyPriorityQueue<T, Comparator>();
    this->evaluatedNodes = 0;
}

template<class T, class Solution, class Comparator>
State<T> *Searcher<T, Solution, Comparator>::PopOpenList() {
    this->evaluatedNodes++;
    return openList.Pop();
}

template<class T, class Solution, class Comparator>
void Searcher<T, Solution, Comparator>::PushOpenList(State<T> *state) {
    openList.Push(state);
}

template<class T, class Solution, class Comparator>
int Searcher<T, Solution, Comparator>::OpenListSize() {
    return openList.GetSize();
}

template<class T, class Solution, class Comparator>
int Searcher<T, Solution, Comparator>::GetNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}

template<class T, class Solution, class Comparator>
bool Searcher<T, Solution, Comparator>::IsInOpenList(State<T> *state) {
    return this->openList.IsInQueue(state);
}

template<class T, class Solution, class Comparator>
void Searcher<T, Solution, Comparator>::UpdateQueue() {
    this->openList.Update();
}

#endif //FLIGHTSIMULATORMASTER_SEARCHER_H
