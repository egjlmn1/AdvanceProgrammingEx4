//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H
#define FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H

#include "../State.h"
#include "Searcher.h"
#include <bits/stdc++.h>

template <class T>
class BestFirstSearch : Searcher<T, vector<State<T>*>> {
private:
    unordered_map<T, State<T>> closed;
public:
    BestFirstSearch<T>();
    vector<State<T>*> search(ISearchable<T> *searchable);
    vector<State<T>*> CreateSolution(ISearchable<T> *searchable);
};

#endif //FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H
