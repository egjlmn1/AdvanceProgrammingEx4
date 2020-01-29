//
// Created by ophir on 1/23/2020.
//

#include "MatrixSolution.h"

string MatrixSolution::to_string() {
    string solution;
    for (tuple<State<string>*, position> stateTuple : this->answerVec) {
        switch (stateTuple.second) {
            case UP:
                solution += "Up ";
                break;
            case DOWN:
                solution += "Down ";
                break;
            case LEFT:
                solution += "Left ";
                break;
            case RIGHT:
                solution += "Right ";
                break;
        }
    }
}