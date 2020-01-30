//
// Created by egjlmn1 on 1/29/20.
//

#include "MatrixSearchSolverAdapter.h"
#include "../SearchingAlgorithms/Searchers/DepthFirstSearch.h"
#include "../SearchingAlgorithms/Searchers/BreadthFirstSearch.h"
#include "../SearchingAlgorithms/Searchers/BestFirstSearch.h"
#include "../SearchingAlgorithms/Searchers/AStar.h"
#include "../FileCacheManager.h"

StringSolution MatrixSearchSolverAdapter::solve(MatrixProblem& problem) {
    FileCacheManager<MatrixProblem, string> cache;
    //check if solution already exist
    if (cache.has_solution(problem)) {
        StringSolution s(cache.get_solution(problem));
        return s;
    }

    MatrixSearchable *searchable = new MatrixSearchable(
            problem.get_length(), problem.get_width(), problem.get_matrix(), problem.get_start(), problem.get_end());


    AStar<string> *searcher = new AStar<string>();

    try {
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
            to_send.append(to_string((int) state2->GetRouteCost()));
            to_send.append("), ");
        }
        cout << searcher->GetNumberOfNodesEvaluated() << endl;
        to_send = to_send.substr(0, to_send.size() - 2);
        cache.save_solution(problem, to_send);
        StringSolution sol(to_send);
        return sol;
    } catch (const char* e) {
        return StringSolution("failed solving the problem");
    }
}
