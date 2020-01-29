//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_INTERFACES_H
#define FLIGHTSIMULATORMASTER_INTERFACES_H

#include "streambuf"
#include <string>

using namespace std;

namespace client_side
{
    class ClientHandler {
    public:
        virtual void handleClient(int client_socket) = 0;

    };
}

namespace server_side
{
    using namespace client_side;
    class Server {
        /*
         * open server and wait for clients
         */
        virtual void open(int port, ClientHandler* c) = 0;

        /*
         * close the server
         */
        virtual void stop() = 0;
    };
}

namespace problem_solving
{
    template <class Problem, class Solution>
    class Solver {
    public:
        virtual Solution solve(Problem) = 0;
    };

    template <class Problem, class Solution>
    class CacheManager {
    public:
        virtual bool has_solution(Problem& p) = 0;
        virtual Solution get_solution(Problem& p) = 0;
        virtual void save_solution(Problem& p, Solution& s) = 0;
    };
}


#endif //FLIGHTSIMULATORMASTER_INTERFACES_H
