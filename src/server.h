//
// Created by whiterose on 1/31/26.
//

#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H
#include <netinet/in.h>

class Server
{
public:
    bool CreateSocket();

private:
    int sock = -1;
    sockaddr_in serverAddr;
};

#endif