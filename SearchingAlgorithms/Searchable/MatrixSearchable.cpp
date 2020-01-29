//
// Created by ophir on 1/22/2020.
//

#include <iostream>
#include "../State.h"
#include "MatrixSearchable.h"

MatrixSearchable::MatrixSearchable(int len, int wid, double *mat, pair<int, int> start, pair<int, int> end) {
    this->length = len;
    this->width = wid;
    this->matrix = mat;
    this->start = start;
    this->end = end;
    this->InitializeStates();
}


void MatrixSearchable::InitializeStates() {
    this->states = (State<string> ***) malloc(this->length * sizeof(State<string> **));
    for (int i = 0; i < this->length; i++) {
        this->states[i] = (State<string> **) malloc(this->width * sizeof(State<string> *));
    }

    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->width; j++) {
            this->states[i][j] = new State<string>(to_string(i) + " " + to_string(j),
                                                   matrix[i * this->length + j], CalcHeuristic(i, j));
        }
    }
}


State<string> *MatrixSearchable::GetInitialState() {
    return this->states[this->start.first][this->start.second];
}


State<string> *MatrixSearchable::GetGoalState() {
    return this->states[this->end.first][this->end.second];
}


vector<State<string> *> MatrixSearchable::GetAllPossibleStates(State<string> *s) {
    vector<State<string> *> neighbors;
    int stateLen = this->GetLengthByState(s);
    int stateWid = this->GetWidthByState(s);


    if (stateLen == this->length || stateWid == this->width) {
        cerr << "Error in matrix searchable get all possible states" << endl;
        exit(1);
    }

    if (stateLen == 0) {
        neighbors.push_back(this->states[stateLen + 1][stateWid]);
    } else if (stateLen == this->length - 1) {
        neighbors.push_back(this->states[stateLen - 1][stateWid]);
    } else {
        neighbors.push_back(this->states[stateLen - 1][stateWid]);
        neighbors.push_back(this->states[stateLen + 1][stateWid]);
    }

    if (stateWid == 0) {
        neighbors.push_back(this->states[stateLen][stateWid + 1]);
    } else if (stateWid == this->length - 1) {
        neighbors.push_back(this->states[stateLen][stateWid - 1]);
    } else {
        neighbors.push_back(this->states[stateLen][stateWid - 1]);
        neighbors.push_back(this->states[stateLen][stateWid + 1]);
    }

    return neighbors;
}


int MatrixSearchable::GetLengthByState(State<string> *s) {
    int len = this->length;
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->width; j++) {
            if (this->states[i][j]->Equals(s)) {
                return i;
            }
        }
    }
    return len;
}

/**
 * Returns the y value of state in matrix
 * @param s- the state
 * @return the y value of state in matrix
 */
int MatrixSearchable::GetWidthByState(State<string> *s) {
    int wid = this->width;
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->width; j++) {
            if (this->states[i][j]->Equals(s)) {
                return j;
            }
        }
    }
    return wid;

}

double MatrixSearchable::CalcHeuristic(int i, int j) {
    // manhattan distance
    return abs(i - this->end.first) + abs(j - this->end.second);
}