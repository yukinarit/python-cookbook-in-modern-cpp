/// echoserv.cpp
///

#include <iostream>
#include <string>

#include <fmt/format.h>
#include <zmq.hpp>

int main(int argc, char* argv[]) {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    return 0;
}
