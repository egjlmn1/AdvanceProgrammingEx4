//
// Created by egjlmn1 on 1/29/20.
//

#ifndef FLIGHTSIMULATORMASTER_MATRIXSOLVER_H
#define FLIGHTSIMULATORMASTER_MATRIXSOLVER_H

#include "../Interfaces.h"
#include "../SearchingAlgorithms/Searchable/MatrixSearchable.h"
#include "../Problems/MatrixProblem.h"
#include "../Solutions/StringSolution.h"


using namespace problem_solving;
class MatrixSolver : Solver<MatrixProblem, StringSolution> {
public:
    StringSolution solve(MatrixProblem& problem) override;
};


#endif //FLIGHTSIMULATORMASTER_MATRIXSOLVER_H
