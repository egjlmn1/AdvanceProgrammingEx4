//
// Created by ophir on 1/22/2020.
//

#include "Solution.h"

template <class T>
Solution<T>::Solution(vector<State<T>> vec) {
    this->answerVec = vec;
}

template <class T>
vector<State<T>> Solution<T>::GetSolutionVector() {
    return this->answerVec;
}