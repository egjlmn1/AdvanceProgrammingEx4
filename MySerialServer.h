//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_MYSERIALSERVER_H
#define FLIGHTSIMULATORMASTER_MYSERIALSERVER_H

#include "Inteface.h"

using namespace server_side;
class MySerialServer : public Server{
    void open(int port, ClientHandler* c) override;

    void stop() override;

};


#endif //FLIGHTSIMULATORMASTER_MYSERIALSERVER_H
