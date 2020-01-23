//
// Created by ophir on 1/22/2020.
//

#include "BestFirstSearch.h"

template <class T>
Solution<T>* BestFirstSearch<T>::search(ISearchable<T> searchable) {
    this->PushOpenList(searchable.GetInitialState());
    while (this->OpenListSize() > 0) {
        State<T>* n = this->PopOpenList();
        this->closed.insert(n);
        if (n->Equals(searchable.GetGoalState())) {
            return this->CreateSolution();
        }

        vector<State<T>*> successors = searchable.GetAllPossibleStates(n);


        for (State<T>* state : successors) {
            if (!this->closed.find(state) && !this->IsInOpenList(state)) {
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