#include <iostream>

#include "SearchingAlgorithms/State.h"
#include "SearchingAlgorithms/Searchable/MatrixSearchable.h"
#include "SearchingAlgorithms/Searchers/Astar.h"
#include "SearchingAlgorithms/MatricesGenerator.h"
#include "SearchingAlgorithms/Searchers/BestFirstSearch.h"
#include "SearchingAlgorithms/Searchers/BreadthFirstSearch.h"
#include "SearchingAlgorithms/Searchers/DepthFirstSearch.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    int count = 2;
    vector<MatrixSearchable *> mats = MatricesGenerator::GenerateRandomMatrices(10, 10, 50);


    BestFirstSearch<string> *searcher1 = new BestFirstSearch<string>();
    BreadthFirstSearch<string> *searcher2 = new BreadthFirstSearch<string>();
    DepthFirstSearch<string> *searcher3 = new DepthFirstSearch<string>();
    AStar<string> *searcher4 = new AStar<string>();

    vector<State<string> *> sol;

    int i = 0;
    string s = "";

    for (auto mat : mats) {
        string s = "";
        i++;
        cout << "Matrix " + ::to_string(i) + ":\n" + mat->to_string() + "\n" << endl;
        cout << "\n" << endl;

        sol = searcher1->search(mat);
        cout << "BestFirstSearch:\nEvaluated: " + to_string(searcher1->GetNumberOfNodesEvaluated()) << endl;

        sol = searcher2->search(mat);
        cout << "BreadthFirstSearch:\nEvaluated: " + to_string(searcher2->GetNumberOfNodesEvaluated()) << endl;

        sol = searcher3->search(mat);
        cout << "DepthFirstSearch:\nEvaluated: " + to_string(searcher3->GetNumberOfNodesEvaluated()) << endl;

        try {
            sol = searcher4->search(mat);
            cout << "AStar:\nEvaluated: " + to_string(searcher4->GetNumberOfNodesEvaluated()) << endl;
            cout << "Solution:" << endl;
            for (auto i : sol) {
                s += i->GetState() + ", ";
            }
            cout << s << endl;

            cout << "\n" << endl;
        } catch (const string &e) {
            sol = searcher4->search(mat);
        }


    }
};