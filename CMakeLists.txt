cmake_minimum_required(VERSION 4.1)
project(network)

set(CMAKE_CXX_STANDARD 14)

add_executable(network
        src/socket.cpp
        src/main.cpp
        src/server.h
)
