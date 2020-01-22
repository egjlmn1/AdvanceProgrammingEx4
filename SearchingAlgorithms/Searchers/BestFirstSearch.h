//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H
#define FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H

#include "../State.h"
#include "Searcher.h"
#include <bits/stdc++.h>

template <class T>
class BestFirstSearch : Searcher<T> {
private:
    unordered_set<State<T>> closed;
public:
    BestFirstSearch<T>();
    Solution<T>* search(ISearchable<T> searchable);
    Solution<T>* CreateSolution();
};

#endif //FLIGHTSIMULATORMASTER_BESTFIRSTSEARCH_H
