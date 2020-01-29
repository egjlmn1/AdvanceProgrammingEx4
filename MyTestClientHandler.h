//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_MYTESTCLIENTHANDLER_H
#define FLIGHTSIMULATORMASTER_MYTESTCLIENTHANDLER_H

#include "Interfaces.h"
#include "vector"

using namespace client_side;
class MyTestClientHandler : public ClientHandler{
    void create_problem(const string& data, int socket);
    vector<string> split(string data, char to_split);
public:
    void handleClient(int client_socket) override;
};


#endif //FLIGHTSIMULATORMASTER_MYTESTCLIENTHANDLER_H