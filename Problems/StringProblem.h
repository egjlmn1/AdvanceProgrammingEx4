//
// Created by egjlmn1 on 1/21/20.
//

#ifndef EX4_STRINGPROBLEM_H
#define EX4_STRINGPROBLEM_H


#include "../Inteface.h"

class StringProblem {
    string problem;
public:
    StringProblem(const string &problem) : problem(problem) {}
    string get_string() {return problem;}
    string to_string() {return problem;}

};


#endif //EX4_STRINGPROBLEM_H
