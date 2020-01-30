//
// Created by ophir on 1/29/2020.
//

#include <stdlib.h>
#include <time.h>
#include "MatricesGenerator.h"
#include "Searchable/MatrixSearchable.h"

MatrixSearchable *MatricesGenerator::Generate(int size) {
    double *mat = new double[size * size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat[i * size + j] = rand() % 11 - 1;
        }
    }

    return new MatrixSearchable(size, size, mat, new pair<int, int>(0, 0), new pair<int, int>(size - 1, size - 1));
}

vector<MatrixSearchable *> MatricesGenerator::GenerateRandomMatrices(int count, int minSize, int maxSize) {
    vector<MatrixSearchable *> vec;

    int rangeDelta = ((maxSize - minSize) / count) - 1;
    int range = 0;

    for (int k = 0; k < count; k++) {
        vec.push_back(Generate((rand() % rangeDelta) + range + minSize));
        range += rangeDelta;
    }

    return vec;
}