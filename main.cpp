#include <iostream>

#include "MyParallelServer.h"
#include "MyTestClientHandler.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {

    MyParallelServer s;
    s.open(5400, new MyTestClientHandler());

    return 0;
}
