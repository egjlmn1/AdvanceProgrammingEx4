//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_MYPRIORITYQUEUE_H
#define FLIGHTSIMULATORMASTER_MYPRIORITYQUEUE_H

#include "State.h"
#include "StateComparator.h"
#include <queue>

template <class T>
class MyPriorityQueue {
private:
    priority_queue<State<T>*, vector<State<T>*, StateComparator<T>>> queue;
    int size;
public:
    MyPriorityQueue();
    void Push(State<T>* state);
    void Update();
    State<T>* Pop();
    int GetSize();
    bool IsInQueue(State<T>* n);
};


#endif //FLIGHTSIMULATORMASTER_MYPRIORITYQUEUE_H
