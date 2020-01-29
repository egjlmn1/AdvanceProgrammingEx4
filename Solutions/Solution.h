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
public:
    Solution(vector<State<T>> vec);
    virtual string to_string() = 0;
};

#endif //FLIGHTSIMULATORMASTER_SOLUTION_H
