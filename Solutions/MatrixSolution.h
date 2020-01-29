//
// Created by ophir on 1/23/2020.
//

#ifndef FLIGHTSIMULATORMASTER_MATRIXSOLUTION_H
#define FLIGHTSIMULATORMASTER_MATRIXSOLUTION_H

#include "Solution.h"

enum position {UP, DOWN, RIGHT, LEFT, FINAL};
typedef enum position position;

class MatrixSolution : Solution<string> {
private:
    vector<State<string>*, position> answerVec;
    string to_string();
};

#endif //FLIGHTSIMULATORMASTER_MATRIXSOLUTION_H
