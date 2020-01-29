//
// Created by ophir on 1/29/2020.
//

#include "StateComparator.h"

template <class T>
bool StateComparator<T>::operator()(State<T> *s1, State<T> *s2) {
    return (s1->GetCost() > s2->GetCost());
}