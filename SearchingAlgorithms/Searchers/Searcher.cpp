//
// Created by ophir on 1/22/2020.
//

#include "Searcher.h"

template <class T>
Searcher<T>::Searcher() {
    this->openList = MyPriorityQueue<State<T>>();
    this->evaluatedNodes = 0;
}

template <class T>
State<T> Searcher<T>::PopOpenList() {
    this->evaluatedNodes++;
    return openList.Pop();
}

template <class T>
void Searcher<T>::PushOpenList(State<T>* state) {
    this->openList.Push(state);
}

template <class T>
int Searcher<T>::OpenListSize() {
    return openList->Count;
}

template <class T>
int Searcher<T>::GetNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}