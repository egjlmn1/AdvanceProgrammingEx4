//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H
#define FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H

#include "Interfaces.h"
#include <list>
#include <unordered_map>
#include <fstream>
#include <iostream>


using namespace problem_solving;

template <class Problem, class Solution>
class FileCacheManager : CacheManager<Problem, Solution> {

public:

    bool has_solution(Problem& p) override {
        ifstream ifile(p.to_string());
        return (bool) ifile;
    }

    Solution get_solution(Problem& p) override {
        if (!has_solution(p)) {
            cerr << "an error" << endl;
        }
        try {
            std::ifstream infile(p.to_string(), std::ifstream::binary);
            Solution sol;
            Solution total_solution;

            while (getline(infile, sol)){
                total_solution += sol;
            }

            if (infile.bad()) {
                cerr << "falied reading from file" << endl;
            }


            infile.close();
            return sol;
        }
        catch (const char *e) {
            cerr << e << endl;
        }
    }

    void save_solution(Problem& p, Solution& s) override {
        //save in file
        try {
            std::ofstream outfile(p.to_string(), std::ofstream::binary);
            outfile << s;
            if (outfile.bad()) {
                cerr << "falied writing to file" << endl;
            }
            outfile.close();
        }
        catch (const char *e) {
            cerr << e << endl;
        }
    }
};


#endif //FLIGHTSIMULATORMASTER_FILECACHEMANAGER_H
