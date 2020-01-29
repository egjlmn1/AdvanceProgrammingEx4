//
// Created by egjlmn1 on 1/17/20.
//

#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>

void MySerialServer::open( int port, ClientHandler* c) {
    this->port = port;
    clientHandler = c;
    server_thread = new thread(&MySerialServer::client_listening, this);
}

void MySerialServer::client_listening() {

    // create server socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket";
    }

    // bind socket to IP address
    sockaddr_in address;
    address.sin_family = AF_INET; //in means IP4
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }

    //making socket listen to the port
    if (listen(socketfd, 1) == -1) {
        throw "Error during listening command";
    }

    while (!close_connection) {
        //listen to client
        int client_socket = accept(socketfd, (struct sockaddr *)&address,
                                   (socklen_t*)&address);
        //handle client
        clientHandler->handleClient(client_socket);
        //next client
    }

}

void MySerialServer::stop() {
    close_connection = true;
}
