//
// Created by egjlmn1 on 1/28/20.
//

#ifndef FLIGHTSIMULATORMASTER_MYPARALLELSERVER_H
#define FLIGHTSIMULATORMASTER_MYPARALLELSERVER_H

#include <thread>
#include <list>
#include <vector>
#include "Interfaces.h"

using namespace server_side;
class MyParallelServer : Server{
    thread* server_thread;
    vector<thread*> client_thread;
    ClientHandler* clientHandler;
    int port;
    bool close_connection;
    void client_listening();
public:
    void open(int port, client_side::ClientHandler *c) override;

    void stop() override;
};


#endif //FLIGHTSIMULATORMASTER_MYPARALLELSERVER_H
