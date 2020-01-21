//
// Created by egjlmn1 on 1/21/20.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include "../Inteface.h"
#include "../Problems/StringProblem.h"
#include "../Solutions/StringSolution.h"

using namespace problem_solving;
class StringReverser : Solver<StringProblem, StringSolution> {

public:
    StringSolution solve(StringProblem problem) override;
};


#endif //EX4_STRINGREVERSER_H
