//
// Created by ophir on 1/22/2020.
//

#include <iostream>
#include "MatrixSearchable.h"

template <class T>
MatrixSearchable<T>::MatrixSearchable(int len, int wid, double **mat) {
    this->length = len;
    this->width = wid;
    this->matrix = mat;
    this->InitializeStates();
}

template <class T>
void MatrixSearchable<T>::InitializeStates() {
    this->states = (State<T>***) malloc(this->length * sizeof(State<T>**));
    for (int i = 0; i < this->length; i++) {
        this->states[i] = (State<T>**) malloc(this->width * sizeof(State<T>*));
    }

    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->width; i++) {
            this->states[i][j] = new State<T>(to_string(i) + " " + to_string(j), matrix[i][j]);
        }
    }
}

template <class T>
State<T>* MatrixSearchable<T>::GetInitialState() {
    return this->states[0][0];
}

template <class T>
State<T>* MatrixSearchable<T>::GetGoalState() {
    return this->states[this->length-1][this->width-1];
}

template <class T>
vector<State<T>*> MatrixSearchable<T>::GetAllPossibleStates(State<T> *s) {
    vector<State<T>*> neighbors;
    int stateLen = this->GetLengthByState(s);
    int stateWid = this->GetWidthByState(s);


    if (stateLen == this->length || stateWid == this->width) {
        cerr << "Error in matrix searchable get all possible states" << endl;
        exit(1);
    }

    switch (stateLen) {
        case 0:
            neighbors.push_back(this->states[stateLen + 1][stateWid]);
            break;
        case (this->length-1):
            neighbors.push_back(this->states[stateLen - 1][stateWid]);
            break;
        default:
            neighbors.push_back(this->states[stateLen + 1][stateWid]);
            neighbors.push_back(this->states[stateLen - 1][stateWid]);
    }

    switch (stateWid) {
        case 0:
            neighbors.push_back(this->states[stateLen][stateWid + 1]);
            break;
        case (this->length-1):
            neighbors.push_back(this->states[stateLen][stateWid - 1]);
            break;
        default:
            neighbors.push_back(this->states[stateLen][stateWid + 1]);
            neighbors.push_back(this->states[stateLen][stateWid - 1]);
    }

    return neighbors;
}

template <class T>
int MatrixSearchable<T>::GetLengthByState(State<T> *s) {
    int len = this->length;
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->width; i++) {
            if (this->states[i][j]->Equals(s)) {
                len = i;
            }
        }
    }
    return len;
}

template <class T>
int MatrixSearchable<T>::GetWidthByState(State<T> *s) {
    int wid = this->width;
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->width; i++) {
            if (this->states[i][j]->Equals(s)) {
                wid = i;
            }
        }
    }
    return wid;
}