//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_MYSERIALSERVER_H
#define FLIGHTSIMULATORMASTER_MYSERIALSERVER_H

#include "Interfaces.h"
#include <thread>

using namespace server_side;
class MySerialServer : public Server{
    thread* server_thread;
    ClientHandler* clientHandler;
    int port;
    bool close_connection;
    void client_listening();
public:
    void open(int port, ClientHandler* c) override;
    void stop() override;
};


#endif //FLIGHTSIMULATORMASTER_MYSERIALSERVER_H
