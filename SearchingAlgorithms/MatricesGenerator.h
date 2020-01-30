//
// Created by ophir on 1/29/2020.
//

#ifndef MITKADEM4_MATRICESGENERATOR_H
#define MITKADEM4_MATRICESGENERATOR_H

#include "Searchable/MatrixSearchable.h"

class MatricesGenerator {
public:
    MatricesGenerator();

    static MatrixSearchable *Generate(int size);

    static vector<MatrixSearchable *> GenerateRandomMatrices(int count, int minSize, int maxSize);
};

#endif //MITKADEM4_MATRICESGENERATOR_H
