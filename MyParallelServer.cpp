//
// Created by egjlmn1 on 1/28/20.
//

#include <netinet/in.h>
#include <iostream>
#include "MyParallelServer.h"

void MyParallelServer::open(int port, client_side::ClientHandler *c) {
    this->port = port;
    clientHandler = c;
    close_connection = false;
    server_thread = new thread(&MyParallelServer::client_listening, this);
    server_thread->join();
}

void MyParallelServer::client_listening() {

    // create server socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        return;
    }

    timeval tv;
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    //open connection to server
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  //or INADDR_ANY
    address.sin_port = htons(port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Could not bind the socket to an IP" << endl;
        return;
    }

    //making socket listen to the port
    if (listen(socketfd, 10) == -1) {
        cerr << "Error during listening command" << endl;
        return;
    }

    while (!close_connection) {
        //listen to client
        int client_socket = accept(socketfd, (struct sockaddr *)&address,
                                   (socklen_t*)&address);
        if (client_socket == -1) {
            cerr << "Error accepting client" << endl;
            return;
        }
        //handle client

        client_thread.push_back(new thread(&ClientHandler::handleClient, clientHandler, client_socket));
    }
}

void MyParallelServer::stop() {
    close_connection = true;
}
