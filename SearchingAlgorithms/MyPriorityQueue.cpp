//
// Created by ophir on 1/22/2020.
//

#include "MyPriorityQueue.h"

template <class T>
MyPriorityQueue<T>::MyPriorityQueue() {
    this->size = 0;
}

template <class T>
void MyPriorityQueue<T>::Push(State<T> *state) {
    this->queue.push(state);
}

template <class T>
void MyPriorityQueue<T>::Update() {
    vector<State<T>*> temp;

    // take all out
    while (!this->queue.empty()) {
        temp.push_back(this->queue.top());
        this->queue.pop();
    }

    // return all
    while(!temp.empty()) {
        this->queue.push(temp.back());
        temp.pop_back();
    }
}

template <class T>
State<T>* MyPriorityQueue<T>::Pop() {
    State<T>* temp = this->queue.top();
    this->queue.pop();
    return temp;
}

template <class T>
int MyPriorityQueue<T>::GetSize() {
    return this->size;
}

template <class T>
bool MyPriorityQueue<T>::IsInQueue(State<T>* n) {
    bool flag = false;
    vector<State<T>*> temp;

    // take all out
    while (!this->queue.empty()) {
        temp.push_back(this->queue.top());
        this->queue.pop();
    }

    for (State<T>* state : temp) {
        if (state->Equals(n)) {
            flag = true;
        }
    }

    // return all
    while(!temp.empty()) {
        this->queue.push(temp.back());
        temp.pop_back();
    }

    return flag;
}