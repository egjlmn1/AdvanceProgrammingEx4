//
// Created by ophir on 1/23/2020.
//

#ifndef FLIGHTSIMULATORMASTER_SEARCHABLESOLUTIONADAPTER_H
#define FLIGHTSIMULATORMASTER_SEARCHABLESOLUTIONADAPTER_H

#include "../SearchingAlgorithms/Searchable/ISearchable.h"
#include "../Solutions/Solution.h"

template <class T>
class SearchableSolutionAdapter {
private:
    ISearchable<T> searchable;
    Solution<T> solution;
public:
    SearchableSolutionAdapter(ISearchable<T> searchable1, Solution<T> solution1);
    Solution<T> GetAdaptedSolution();
};

#endif //FLIGHTSIMULATORMASTER_SEARCHABLESOLUTIONADAPTER_H
