#include <iostream>
#include <thread>

#include "Inteface.h"
#include "SearchingAlgorithms/Searchable/MatrixSearchable.h"
#include "SearchingAlgorithms/Searchers/BestFirstSearch.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    double **mat = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        mat[i] = (double*)malloc(3 * sizeof(double));
    }
    mat[0][0] = 9;
    mat[0][1] = -1;
    mat[0][2] = -1;
    mat[1][0] = 8;
    mat[1][1] = -1;
    mat[1][2] = -1;
    mat[2][0] = 7;
    mat[2][1] = 6;
    mat[2][2] = 5;

    MatrixSearchable* searchable = new MatrixSearchable(3, 3, mat);
    BestFirstSearch<string>* searcher = new BestFirstSearch<string>();

    vector<State<string>*> sol = searcher->search(*searchable);

    for (auto it = sol.begin(); it != sol.end(); ++it) {
        (*it)->GetState();
    }
}
