/// echoserv.cpp
///

#include <iostream>
#include <string>

#include <fmt/format.h>
#include <zmqpp/zmqpp.hpp>

int main(int argc, char* argv[]) {
    zmqpp::context_t context;
    zmqpp::socket_t socket(context, zmqpp::socket_type::rep);
    // SO_REUSEADDR is not supported in ZeroMQ, so try ZMQ_SNDBUF instead
    socket.set(zmqpp::socket_option::send_buffer_size, 40000);
    socket.bind("tcp://*:20000");
    fmt::print("Echo server running on port 20000\n");

    while (true) {
        zmqpp::message request;
        socket.receive(request);

        std::string text;
        request >> text;
        fmt::print("Received: {}\n", text);

        zmqpp::message reply;
        reply << text;
        socket.send(reply);
    }

    return 0;
}
