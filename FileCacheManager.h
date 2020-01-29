//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H
#define FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H

#include "Interfaces.h"
#include <list>
#include <unordered_map>
#include <fstream>


using namespace problem_solving;

template <class Problem, class Solution>
class FileCacheManager : CacheManager<Problem, Solution> {

    int size;
public:
    FileCacheManager(int size) : size(size) {}

    bool has_solution(Problem& p) override {
        ifstream ifile(p.to_string());
        return (bool) ifile;
    }

    Solution get_solution(Problem& p) override {
        if (!has_solution(p)) {
            throw "an error";
        }

        try {
            std::ifstream infile(p.to_string(), std::ifstream::binary);
            Solution obj;
            infile.read((char *) &obj, sizeof(obj));
            if (infile.bad()) {
                throw "falied reading from file";
            }
            infile.close();
            return obj;
        }
        catch (const char *e) {
            throw e;
        }
    }

    void save_solution(Problem& p, Solution& s) override {
        //save in file
        try {
            std::ofstream outfile(p.to_string(), std::ofstream::binary);
            outfile.write((char *) &s, sizeof(s));
            if (outfile.bad()) {
                throw "falied writing to file";
            }
            outfile.close();
        }
        catch (const char *e) {
            throw e;
        }
    }
};


#endif //FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H
