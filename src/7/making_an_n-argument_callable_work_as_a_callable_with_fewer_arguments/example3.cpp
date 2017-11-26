/// example.cpp
///
/// Using partial to supply extra arguments to a callback function

#include <experimental/net>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>

using std::experimental::net::v1::ip::tcp;

const int max_length = 1024;

class EchoServer {
public:
    EchoServer(unsigned short port) {
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), port));
        while (true) {
            tcp::socket sock(io);
            acceptor.accept(io);
            std::thread([sock = std::move(sock)]() {
                try {
                    char data[max_length];
                    std::error_code error;
                    std::size_t length = sock.read_some(std::experimental::net::buffer(data));
                } catch (const std::exception& e) {
                }

            }).detach();
        }
    }

    std::experimental::net::io_context io;
};

int main() {
    EchoServer server(15000);

    return 0;
}
