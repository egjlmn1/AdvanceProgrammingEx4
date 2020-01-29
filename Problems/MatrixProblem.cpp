//
// Created by egjlmn1 on 1/29/20.
//

#include "MatrixProblem.h"

void MatrixProblem::hashing() {
    string to_hash;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            to_hash.append(std::to_string(matrix[i * width + j]));
        }
    }
    to_hash.append(std::to_string(start.first));
    to_hash.append(std::to_string(start.second));
    to_hash.append(std::to_string(end.first));
    to_hash.append(std::to_string(end.second));

    hash<string> hasher;
    size_t hash = hasher(to_hash);
    problem = std::to_string(hash);
}
