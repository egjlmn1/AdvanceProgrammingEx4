

#include <iostream>

#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MyParallelServer.h"

/*
 * Main function.
 */
int main(int argc, char *argv[]) {
    MyParallelServer s;
    try {
        if (argc == 2) {
            s.open(atoi(argv[1]), new MyTestClientHandler());
        } else {
            s.open(5411, new MyTestClientHandler());
        }
    } catch (const char* e) {
        cout << e << endl;
    }
    return 0;
}
