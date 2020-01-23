//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_MATRIXSEARCHABLE_H
#define FLIGHTSIMULATORMASTER_MATRIXSEARCHABLE_H

#include "ISearchable.h"

template <class T>
class MatrixSearchable : ISearchable<T> {
private:
    int length;
    int width;
    double **matrix;
    State<T>*** states;
public:
    MatrixSearchable(int len, int wid, double **mat);
    void InitializeStates();
    State<T>* GetInitialState() = 0;
    State<T>* GetGoalState() = 0;
    vector<State<T>*> GetAllPossibleStates(State<T>* s) = 0;
    int GetLengthByState(State<T>* state);
    int GetWidthByState(State<T>* state);

};

#endif //FLIGHTSIMULATORMASTER_MATRIXSEARCHABLE_H
