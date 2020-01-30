//
// Created by ophir on 1/29/2020.
//

#ifndef MITKADEM4_ASTAR_H
#define MITKADEM4_ASTAR_H

#include <algorithm>
#include <unordered_set>
#include "../State.h"
#include "Searcher.h"
#include "../AddHeuristicComparator.h"

template<class T>
class AStar : Searcher<T, vector<State<T> *>, AddHeuristicComparator<T>> {
private:
    unordered_set <T> closed;
public:

    AStar() {}

    vector<State<T> *> search(ISearchable<T> *searchable);

    vector<State<T> *> CreateSolution(ISearchable<T> *searchable);

    int GetNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    };
};

template<class T>
vector<State<T> *> AStar<T>::search(ISearchable<T> *searchable) {
    this->evaluatedNodes = 0;
    this->closed.clear();
    this->EmptyQueue();

    this->PushOpenList(searchable->GetInitialState());
    while (this->OpenListSize() > 0) {
        this->evaluatedNodes++;
        State<T> *n = this->PopOpenList();
        this->closed.insert(n->GetState());

        if (n->Equals(searchable->GetGoalState())) {
            return this->CreateSolution(searchable);
        }

        vector<State<T> *> successors = searchable->GetAllPossibleStates(n);

        for (State<T> *state : successors) {
            if (state->GetCost() == -1) {
                continue;
            }

            if (state->GetCost() + n->GetRouteCost() < state->GetRouteCost()) {
                state->UpdatePrevious(n);
                state->UpdateRouteCost(n->GetRouteCost() + state->GetCost());
                this->PushOpenList(state);
                this->UpdateQueue();

                if (!this->IsInOpenList(state)) {
                    this->PushOpenList(state);
                }
            }

            /*
            if (!searchable->GetInitialState()->Equals(n)) {
                if (n->GetPrevious()->Equals(state)) {
                    continue;
                }
            }

            if (!this->IsInOpenList(state)) {
                state->UpdatePrevious(n);
                state->UpdateRouteCost(n->GetRouteCost() + state->GetCost());
                this->PushOpenList(state);
                this->UpdateQueue();
            } else {
                double newCost = state->GetCost() + n->GetRouteCost();
                if (newCost < state->GetCost()) {

                    state->UpdatePrevious(n);
                    state->UpdateRouteCost(newCost);
                    this->UpdateQueue();
                }
            }
             */
        }
    }
    return vector<State<T> *>();
}


template<class T>
vector<State<T> *> AStar<T>::CreateSolution(ISearchable<T> *searchable) {
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

#endif //MITKADEM4_ASTAR_H
