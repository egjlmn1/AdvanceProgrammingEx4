//
// Created by ophir on 1/22/2020.
//

#include "BestFirstSearch.h"

template <class T>
vector<State<T>*> BestFirstSearch<T>::search(ISearchable<T> *searchable) {
    this->PushOpenList(searchable->GetInitialState());
    while (this->OpenListSize() > 0) {
        State<T>* n = this->PopOpenList();
        this->closed.insert(n->GetState(), n);
        if (n->Equals(searchable->GetGoalState())) {
            return this->CreateSolution();
        }

        vector<State<T>*> successors = searchable->GetAllPossibleStates(n);


        for (State<T>* state : successors) {
            if (!this->closed.find(state) && !this->IsInOpenList(state)) {
                if (state->GetCost() == -1) {
                    continue;
                }
                state->UpdatePrevious(n);
                state->UpdateCost(state->GetCost() + n->GetCost());
                this->PushOpenList(state);
            } else {
                if (!this->IsInOpenList(state)) {
                    state->UpdatePrevious(n);
                    state->UpdateCost(state->GetCost() + n->GetCost());
                    this->PushOpenList(state);
                } else {
                    double newCost = state->GetCost() - state->GetPrevious()->GetCost() + n->GetCost();
                    if (newCost < state->GetCost()) {
                        state->UpdatePrevious(n);
                        state->UpdateCost(newCost);
                        this->UpdateQueue();
                    }
                }
            }
        }
    }
}

template <class T>
vector<State<T>*> BestFirstSearch<T>::CreateSolution(ISearchable<T> *searchable) {
    vector<State<T> *> solution;
    State<T> *last = searchable.GetGoalState();

    State<T> *prev = last;
    while (prev != NULL) {
        solution.push_back(prev);
        prev = prev->GetPrevious();
    }

    reverse(solution.begin(), solution.end());



    return solution;
}