//
// Created by whiterose on 1/31/26.
//

#include "server.h"


int main() {
    Server server;
    server.CreateSocket();
    server.BindSocket();
    return 0;
}