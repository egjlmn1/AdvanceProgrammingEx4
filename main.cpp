#include <iostream>

#include "SearchingAlgorithms/State.h"
#include "SearchingAlgorithms/Searchable/MatrixSearchable.h"
#include "SearchingAlgorithms/Searchers/DepthFirstSearch.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    double **mat = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        mat[i] = (double*)malloc(3 * sizeof(double));
    }
    mat[0][0] = 0;
    mat[0][1] = 1;
    mat[0][2] = 0;
    mat[1][0] = -1;
    mat[1][1] = 0;
    mat[1][2] = 0;
    mat[2][0] = 1;
    mat[2][1] = 1;
    mat[2][2] = 0;

    ISearchable<string> *searchable = new MatrixSearchable(3, 3, mat, < 0,
    0 > , );
    DepthFirstSearch<string> *searcher = new DepthFirstSearch<string>();

    vector<State<string> *> sol = searcher->search(searchable);

    for (auto state : sol) {
        cout << state->GetState() << endl;
    }
}
