/// echoserv.cpp
///

#include <iostream>
#include <string>

#include <fmt/format.h>
#include <zmq.hpp>

int main(int argc, char* argv[]) {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:20000");
    fmt::print("Echo server running on port 20000\n");

    while (true) {
        zmq::message_t request;
        socket.recv(&request);
        socket.send(request);
    }
    return 0;
}
