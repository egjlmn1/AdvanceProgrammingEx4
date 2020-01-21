//
// Created by egjlmn1 on 1/21/20.
//

#ifndef EX4_STRINGSOLUTION_H
#define EX4_STRINGSOLUTION_H

#include "../Inteface.h"

class StringSolution {
    string solution;
public:
    StringSolution(const string &solution) : solution(solution) {}
    string get_string() {return solution;}
    string to_string() {return solution;}

};


#endif //EX4_STRINGSOLUTION_H
