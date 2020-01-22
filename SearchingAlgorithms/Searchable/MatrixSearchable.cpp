//
// Created by ophir on 1/22/2020.
//

#include "MatrixSearchable.h"

template <class T>
MatrixSearchable<T>::MatrixSearchable(int len, int wid, int **mat) {
    this->length = len;
    this->width = width;
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
            this->states[i][j] = new State()
        }
    }
}