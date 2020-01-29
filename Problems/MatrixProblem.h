//
// Created by egjlmn1 on 1/29/20.
//

#ifndef FLIGHTSIMULATORMASTER_MATRIXPROBLEM_H
#define FLIGHTSIMULATORMASTER_MATRIXPROBLEM_H

#include "../Interfaces.h"

class MatrixProblem {
    string problem;
    double* matrix;
    int length;
    int width;
    pair<int, int> start;
    pair<int, int> end;
    void hashing();
public:
    MatrixProblem(double *matrix, int length, int width, pair<int, int> s, pair<int, int> e) :
    matrix(matrix), length(length), width(width), end(e), start(s) {
        // TO DO: CREATE STRING FROM MATRIX
        hashing();
    }
    double* get_matrix() {return matrix;}
    int get_width() {return width;}
    int get_length() {return length;}
    pair<int, int> get_start() {return start;}
    pair<int, int> get_end() {return end;}
    string to_string() {return problem;}
};


#endif //FLIGHTSIMULATORMASTER_MATRIXPROBLEM_H
