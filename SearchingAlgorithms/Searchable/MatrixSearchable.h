//
// Created by ophir on 1/22/2020.
//

#ifndef FLIGHTSIMULATORMASTER_MATRIXSEARCHABLE_H
#define FLIGHTSIMULATORMASTER_MATRIXSEARCHABLE_H

#include "ISearchable.h"

class MatrixSearchable : public ISearchable<string> {
private:
    int length;
    int width;
    double *matrix;
    pair<int, int> start;
    pair<int, int> end;
    State<string> ***states;
public:
    MatrixSearchable(int len, int wid, double *mat, pair<int, int>, pair<int, int>);

    void InitializeStates();

    State<string> *GetInitialState() override;

    State<string> *GetGoalState() override;

    vector<State<string> *> GetAllPossibleStates(State<string> *s) override;

    int GetLengthByState(State<string> *state);

    int GetWidthByState(State<string> *state);

    double CalcHeuristic(State<string> *state);

};

#endif //FLIGHTSIMULATORMASTER_MATRIXSEARCHABLE_H
