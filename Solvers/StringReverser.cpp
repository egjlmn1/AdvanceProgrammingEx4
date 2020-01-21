//
// Created by egjlmn1 on 1/21/20.
//

#include <iostream>
#include "StringReverser.h"

StringSolution StringReverser::solve(StringProblem problem) {
    string s = problem.get_string();
    string sol;
    int length = s.size();
    for (int i = length -1; i >= 0; i--) {
        sol.append(1, s[i]);
    }
    return StringSolution(sol);
}
