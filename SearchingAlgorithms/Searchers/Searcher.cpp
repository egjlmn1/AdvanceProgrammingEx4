//
// Created by ophir on 1/22/2020.
//

#include "Searcher.h"

template <class T, class Solution>
Searcher<T, Solution>::Searcher() {
    this->openList = MyPriorityQueue<State<T>>();
    this->evaluatedNodes = 0;
}

template <class T, class Solution>
State<T> Searcher<T, Solution>::PopOpenList() {
    this->evaluatedNodes++;
    return openList.Pop();
}

template <class T, class Solution>
void Searcher<T, Solution>::PushOpenList(State<T>* state) {
    this->openList.Push(state);
}

template <class T, class Solution>
int Searcher<T, Solution>::OpenListSize() {
    return openList->Count;
}

template <class T, class Solution>
int Searcher<T, Solution>::GetNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}

template <class T, class Solution>
bool Searcher<T, Solution>::IsInOpenList(State<T>* state) {
    return this->openList.IsInQueue(state);
}

template <class T, class Solution>
void Searcher<T, Solution>::UpdateQueue() {
    this->openList.Update();
}