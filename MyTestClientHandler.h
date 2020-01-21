//
// Created by egjlmn1 on 1/17/20.
//

#ifndef FLIGHTSIMULATORMASTER_MYTESTCLIENTHANDLER_H
#define FLIGHTSIMULATORMASTER_MYTESTCLIENTHANDLER_H

#include "Inteface.h"

using namespace client_side;
class MyTestClientHandler : ClientHandler{
    void handleClient(std::streambuf input_stream, std::streambuf output_stream) override;
};


#endif //FLIGHTSIMULATORMASTER_MYTESTCLIENTHANDLER_H
