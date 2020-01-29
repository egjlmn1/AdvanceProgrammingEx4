#include <iostream>

#include "SearchingAlgorithms/State.h"
#include "SearchingAlgorithms/Searchable/MatrixSearchable.h"
#include "SearchingAlgorithms/Searchers/DepthFirstSearch.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    double mat[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    ISearchable<string> *searchable = new MatrixSearchable(3, 3, mat, pair<int, int>(0, 0), pair<int, int>(0, 0));
    DepthFirstSearch<string> *searcher = new DepthFirstSearch<string>();

    vector<State<string> *> sol = searcher->search(searchable);

    for (auto state : sol) {
        cout << state->GetState() << endl;
    }
}
