//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_MYPRIORITYQUEUE_H
#define FLIGHTSIMULATORMASTER_MYPRIORITYQUEUE_H

#include "State.h"
#include "StateComparator.h"
#include <queue>

template<class T, class Comparator>
class MyPriorityQueue {
private:
    priority_queue<State<T> *, vector<State<T> *>, Comparator> queue;
    int size;
public:
    MyPriorityQueue();
    void Push(State<T>* state);
    void Update();
    State<T>* Pop();
    int GetSize();
    bool IsInQueue(State<T>* n);
};

template<class T, class Comparator>
MyPriorityQueue<T, Comparator>::MyPriorityQueue() {
    this->size = 0;
}

template<class T, class Comparator>
void MyPriorityQueue<T, Comparator>::Push(State<T> *state) {
    this->queue.push(state);
    this->size++;
}

template<class T, class Comparator>
void MyPriorityQueue<T, Comparator>::Update() {
    vector<State<T> *> temp;

    // take all out
    while (!this->queue.empty()) {
        temp.push_back(this->queue.top());
        this->queue.pop();
    }

    // return all
    while (!temp.empty()) {
        this->queue.push(temp.back());
        temp.pop_back();
    }
}

template<class T, class Comparator>
State<T> *MyPriorityQueue<T, Comparator>::Pop() {
    State<T> *temp = this->queue.top();
    this->queue.pop();
    this->size--;
    return temp;
}

template<class T, class Comparator>
int MyPriorityQueue<T, Comparator>::GetSize() {
    return this->size;
}

template<class T, class Comparator>
bool MyPriorityQueue<T, Comparator>::IsInQueue(State<T> *n) {
    bool flag = false;
    vector<State<T> *> temp;

    // take all out
    while (!this->queue.empty()) {
        temp.push_back(this->queue.top());
        this->queue.pop();
    }

    for (State<T> *state : temp) {
        if (state->Equals(n)) {
            flag = true;
        }
    }

    // return all
    while (!temp.empty()) {
        this->queue.push(temp.back());
        temp.pop_back();
    }

    return flag;
}

#endif //FLIGHTSIMULATORMASTER_MYPRIORITYQUEUE_H
