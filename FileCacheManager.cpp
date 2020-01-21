//
// Created by egjlmn1 on 1/17/20.
//

#include <fstream>
#include "FileCacheManager.h"

template <class Problem, class Solution>
bool FileCacheManager<Problem, Solution>::has_solution(Problem p) {
    ifstream ifile(p.to_string());
    return (bool) ifile;
}


template <class Problem, class Solution>
Solution FileCacheManager<Problem, Solution>::get_solution(Problem p) {
    if (!has_solution(p.to_strio)) {
        throw "an error";
    }
    auto it = map.find(p);
    if (it == map.end()) {
        Solution obj = get_from_file(p);
        if (lst.size() == size) {
            //remove lru and insert
            map.erase(*prev(lst.end()));
            lst.erase(prev(lst.end()));
        }
        lst.push_front(p);
        auto itr = lst.begin();
        map.insert({p, pair<Solution, typename list<Problem>::iterator>(obj, itr)});
        return obj;
    }
    pair<Solution, typename list<Problem>::iterator> pai = it->second;
    lst.remove(p);
    map.erase(p);
    save_solution(p, pai.first);
    return pai.first;

}

template <class Problem, class Solution>
void FileCacheManager<Problem, Solution>::save_solution(Problem p, Solution s) {
    if (has_solution(p)) {
        //exist
        auto it = map.find(p);
        if (it != map.end()) {
            //remove from map and list
            lst.remove(p);
            map.erase(p );
        }
        if (lst.size() == size) {
            //remove lru and insert
            map.erase(*prev(lst.end()));
            lst.erase(prev(lst.end()));
        }
        lst.push_front(p);
        auto itr = lst.begin();
        map.insert({p, pair<Solution, typename list<Problem>::iterator>(s, itr)});
        //update in file will be done at the end of the function

    } else {
        //create new
        if (lst.size() == size) {
            //remove lru and insert
            map.erase(*prev(lst.end()));
            lst.erase(prev(lst.end()));
        }
        lst.push_front(p);
        auto itr = lst.begin();
        map.insert({p, pair<Solution, typename list<Problem>::iterator>(s, itr)});
    }
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
