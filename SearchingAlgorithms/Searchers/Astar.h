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
    searchable->Reset();
    searchable->GetInitialState()->UpdateRouteCost(searchable->GetInitialState()->GetCost());

    this->PushOpenList(searchable->GetInitialState());
    while (this->OpenListSize() > 0) {
        this->evaluatedNodes++;
        State<T> *n = this->PopOpenList();
        this->closed.insert(n->GetState());

        if (n->GetCost() == -1) {
            cout << "Uh oh: -1 in bad spot" << endl;
        }

        if (n->Equals(searchable->GetGoalState())) {
            return this->CreateSolution(searchable);
        }

        vector<State<T> *> successors = searchable->GetAllPossibleStates(n);
        for (State<T> *state : successors) {

            if (state->GetCost() == -1) {
                continue;
            }

            if (this->closed.find(state->GetState()) == this->closed.end() && !this->IsInOpenList(state)) {
                double newCost = n->GetRouteCost() + state->GetCost();

                if (newCost < state->GetRouteCost()) {
                    state->UpdatePrevious(n);
                    state->UpdateRouteCost(newCost);
                    this->PushOpenList(state);
                    this->UpdateQueue();
                }
            }

            if (!this->IsInOpenList(state) && this->closed.find(state->GetState()) != this->closed.end()) {
                double newCost = n->GetRouteCost() + state->GetCost();

                if (newCost < state->GetRouteCost()) {
                    state->UpdatePrevious(n);
                    state->UpdateRouteCost(newCost);
                    this->PushOpenList(state);
                    this->closed.erase(state->GetState());
                    this->UpdateQueue();
                }
            }

            if (this->IsInOpenList(state)) {
                double newCost = n->GetRouteCost() + state->GetCost();

                if (newCost < state->GetRouteCost()) {
                    state->UpdatePrevious(n);
                    state->UpdateRouteCost(newCost);
                    this->UpdateQueue();
                }
            }

            /*
            if (state->GetCost() == -1 || this->closed.find(state->GetState()) != this->closed.end()) {
                continue;
            }

            double newCost = n->GetRouteCost() + state->GetCost();

            if (newCost < state->GetRouteCost()) {
                state->UpdatePrevious(n);
                state->UpdateRouteCost(newCost);
                if (!this->IsInOpenList(state)) {
                    this->PushOpenList(state);
                }
                this->UpdateQueue();
            }
            */
        }
    }
    cout << "Got stuck" << endl;
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
