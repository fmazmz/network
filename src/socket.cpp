//
// Created by whiterose on 1/31/26.
//

#include <iostream>
#include <ostream>
#include <arpa/inet.h>
#include "server.h"

bool Server::CreateSocket()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        std::cout << "Socket creation failed" << "\n";
        return false;
    }
    std::cout << "Server socket created" << "\n";
    this -> sock = serverSocket;
    return true;
}