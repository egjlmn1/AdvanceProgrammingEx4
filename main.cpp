#include <iostream>
#include <thread>


#include "Solutions/StringSolution.h"
#include "Solvers/StringReverser.h"
#include "Problems/StringProblem.h"
#include "Inteface.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    StringReverser* s = new StringReverser();
    string sol = s->solve(new StringProblem("123"))->get_string();
    cout << sol << endl;
}
