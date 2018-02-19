/// echoclient.cpp
///

#include <iostream>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include <zmq.hpp>

int main(int argc, char* argv[]) {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.connect("tcp://localhost:20000");

    zmq::message_t request(5);
    memcpy(request.data(), "Hello", 5);
    socket.send(request);

    zmq::message_t reply;
    socket.recv(&reply);
    std::string_view buffer((const char*)reply.data(), reply.size());
    fmt::print("Response: {}\n", buffer);
}
