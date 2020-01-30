//
// Created by egjlmn1 on 1/21/20.
//

#ifndef EX4_STRINGSOLUTION_H
#define EX4_STRINGSOLUTION_H

#include "../Interfaces.h"
#include "Solution.h"

class StringSolution {
    string solution;
public:
    explicit StringSolution(string solution) : solution(solution) {}
    StringSolution() : solution("err") {}
    string to_string() {return solution;}
    string set_string(string s) {solution = s;}

};



#endif //EX4_STRINGSOLUTION_H
