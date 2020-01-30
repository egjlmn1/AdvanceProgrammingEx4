#include <iostream>

#include "MyParallelServer.h"
#include "MyTestClientHandler.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    MyParallelServer s;
    int port = 5400;
    if (argc >= 2) {
        try {
            port = atoi(argv[1]);
        } catch (const char* e) {

        }
    }
    s.open(port, new MyTestClientHandler());

    return 0;
}
