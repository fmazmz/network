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
        std::cout << "[-] Socket creation failed" << "\n";
        return false;
    }
    std::cout << "[+] Server socket created" << "\n";
    this -> sock = serverSocket;
    return true;
}

bool Server::BindSocket()
{
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(this->port);

    if (bind(this->sock, reinterpret_cast<struct sockaddr *>(&serverAddr), sizeof(serverAddr)) < 0)
    {
        std::cout << "[-] Bind socket failed\n";
        return false;
    }

    std::cout << "[+] Bind socket success, port: " << this->port << "\n";
    return true;
}

bool Server::Listen()
{
    if (listen(this->sock, 10) < 0)
    {
        std::cout << "[-] Error while entering passive listen mode" << "\n";
        return false;
    }

    std::cout << "[+] Server socket listening on port: " << this->port << "\n";
    return true;
}