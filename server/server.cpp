#include <iostream>
#include "asio.hpp"

using namespace asio;
using namespace asio::ip;

int main() {
    io_context service;
    tcp::endpoint endpoint(tcp::v4(), 1234);
    tcp::acceptor acceptor(service, endpoint);

    while (true) {
        tcp::socket socket(service);
        acceptor.accept(socket);

        std::string message = "Hello, client!";
        error_code ignored_error;
        write(socket, buffer(message), ignored_error);
    }

    return 0;
}
