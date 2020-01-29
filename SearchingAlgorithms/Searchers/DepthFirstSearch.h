//
// Created by ophir on 1/29/2020.
//

#ifndef MITKADEM4_DEPTHFIRSTSEARCH_H
#define MITKADEM4_DEPTHFIRSTSEARCH_H

#include <unordered_set>
#include <queue>
#include <algorithm>

#include "Searcher.h"

template<class T>
class DepthFirstSearch : Searcher<T, vector<State<T> *>, StateComparator<T>> {
public:
    DepthFirstSearch<T>() {}

    vector<State<T> *> search(ISearchable<T> *searchable);

    vector<State<T> *> CreateSolution(ISearchable<T> *searchable);
};


template<class T>
vector<State<T> *> DepthFirstSearch<T>::search(ISearchable<T> *searchable) {
    queue<State<T> *> queue;
    unordered_set<T> visited;

    State<T> *n = searchable->GetInitialState();
    queue.push(n);
    visited.insert(n->GetState());

    while (!queue.empty()) {
        auto s = queue.front();
        queue.pop();

        vector<State<T> *> neighbors = searchable->GetAllPossibleStates(s);

        for (State<T> *state : neighbors) {
            if (state->GetCost() != -1 && visited.find(state->GetState()) == visited.end()) {
                state->UpdatePrevious(s);
                visited.insert(state->GetState());
                queue.push(state);

                if (state->Equals(searchable->GetGoalState())) {
                    return CreateSolution(searchable);
                }
            }
        }
    }
    return vector<State<T> *>();
}


template<class T>
vector<State<T> *> DepthFirstSearch<T>::CreateSolution(ISearchable<T> *searchable) {
    vector<State<T> *> solution;
    State<T> *last = searchable->GetGoalState();

    State<T> *prev = last;
    while (prev != NULL) {
        solution.push_back(prev);
        prev = prev->GetPrevious();
    }

    reverse(solution.begin(), solution.end());

    return solution;
}

#endif //MITKADEM4_DEPTHFIRSTSEARCH_H
