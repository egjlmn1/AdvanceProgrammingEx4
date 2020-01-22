//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_SOLUTION_H
#define FLIGHTSIMULATORMASTER_SOLUTION_H

#include <vector>
#include "../SearchingAlgorithms/State.h"

template <class T>
class Solution {
private:
    vector<State<T>> answerVec;
public:
    Solution(vector<State<T>> vec);
};

#endif //FLIGHTSIMULATORMASTER_SOLUTION_H
