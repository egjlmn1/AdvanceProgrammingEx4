//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H
#define FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H

#include "Inteface.h"
#include <list>
#include <unordered_map>

using namespace problem_solving;

template <class Problem, class Solution>
class FileCacheManager : CacheManager<Problem, Solution> {

    int size;
    unordered_map<Problem, pair<Solution, typename list<Problem>::iterator>> map;
    list<Problem> lst;
public:

    bool has_solution(Problem p) override;

    Solution get_solution(Problem p) override;

    void save_solution(Solution s, Problem p) override;
};


#endif //FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H
