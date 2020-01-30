//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H
#define FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H

#include <algorithm>
#include <unordered_set>
#include "../State.h"
#include "Searcher.h"

template <class T>
class BestFirstSearch : Searcher<T, vector<State<T> *>, StateComparator<T>> {
private:
    unordered_set<T> closed;
public:
    BestFirstSearch<T>() {}
    vector<State<T>*> search(ISearchable<T> *searchable);
    vector<State<T>*> CreateSolution(ISearchable<T> *searchable);

    int GetNumberOfNodesEvaluated() {
        return Searcher<T, vector<State<T> *>, StateComparator<T>>::GetNumberOfNodesEvaluated();
    };
};


template<class T>
vector<State<T> *> BestFirstSearch<T>::search(ISearchable<T> *searchable) {

    /*
    this->evaluatedNodes = 0;
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
            if (this->closed.find(state->GetState()) == this->closed.end() && !this->IsInOpenList(state)) {
                if (state->GetCost() == -1) {
                    continue;
                }
                state->UpdatePrevious(n);
                state->UpdateCost(state->GetCost() + n->GetCost());
                this->PushOpenList(state);
            } else {
                if (state->Equals(n->GetPrevious())) {
                    continue;
                }
                double newCost = state->GetCost() - state->GetPrevious()->GetCost() + n->GetCost();
                if (newCost < state->GetCost()) {
                    state->UpdatePrevious(n);
                    state->UpdateCost(newCost);
                    this->UpdateQueue();
                }

            }
        }
    }
    return vector<State<T> *>();*/

    this->evaluatedNodes = 0;
    this->closed.clear();
    this->EmptyQueue();
    searchable->GetInitialState()->UpdateRouteCost(0);
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
            if (!n->Equals(searchable->GetInitialState())) {
                if (state->GetCost() == -1 || n->GetPrevious()->Equals(state)) {
                    continue;
                }
            }


            if (!this->IsInOpenList(state) && this->closed.find(state->GetState()) == this->closed.end()) {
                state->UpdatePrevious(n);
                state->UpdateRouteCost(n->GetRouteCost() + state->GetRouteCost());
                this->PushOpenList(state);
                this->UpdateQueue();
            } else {
                double newCost = n->GetRouteCost() + state->GetCost();
                if (newCost < state->GetRouteCost()) {
                    state->UpdatePrevious(n);
                    state->UpdateRouteCost(newCost);
                    if (!this->IsInOpenList(state)) {
                        this->PushOpenList(state);
                    }
                    this->UpdateQueue();
                }

            }
        }
    }
    return vector<State<T> *>();
}

template<class T>
vector<State<T> *> BestFirstSearch<T>::CreateSolution(ISearchable<T> *searchable) {
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

#endif //FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H
