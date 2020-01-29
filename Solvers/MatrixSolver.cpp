//
// Created by egjlmn1 on 1/29/20.
//

#include "MatrixSolver.h"
#include "../SearchingAlgorithms/Searchers/BestFirstSearch.h"

StringSolution MatrixSolver::solve(MatrixProblem& problem) {
    MatrixSearchable *searchable = new MatrixSearchable(
            problem.get_length(), problem.get_width(), problem.get_matrix(), problem.get_start(), problem.get_end());

    BestFirstSearch<string> *searcher = new BestFirstSearch<string>();

    vector<State<string> *> solution_path = searcher->search(searchable);

    string to_send;
    int index = 0;
    while (index < (solution_path.size() - 1)) {


        int i1 = searchable->GetLengthByState(solution_path[index]);
        int j1 = searchable->GetWidthByState(solution_path[index]);

        index++;
        auto state2 = solution_path[index];
        int i2 = searchable->GetLengthByState(solution_path[index]);
        int j2 = searchable->GetWidthByState(solution_path[index]);

        if (i1 > i2) {
            //up
            to_send.append("Up (");
        } else if (i2 > i1) {
            //down
            to_send.append("Down (");
        } else if (j1 > j2) {
            //left
            to_send.append("Left (");
        } else {
            //right
            to_send.append("Right (");
        }
        to_send.append(to_string((int) state2->GetCost()));
        to_send.append("), ");
    }
    to_send = to_send.substr(0, to_send.size()-2);

    return to_send;
}
