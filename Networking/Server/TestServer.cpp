#include "TestServer.h"
#include <cstring>

SL::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM,
0, 80, INADDR_ANY, 10){
    
    launch();
}

void SL::TestServer::accepter(){
    struct sockaddr_in address = getSocket()->get_address();
    socklen_t addrLen = sizeof(address);
    new_socket = accept(getSocket() -> get_sock(), (struct sockaddr *) &address,
    &addrLen);

    read(new_socket, buffer, 30000);
}

void SL::TestServer::handler(){
    std::cout << buffer << std::endl;
}


void SL::TestServer::responder(){
    char *hello = "Hello from Server!";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void SL::TestServer::launch(){
    while(true){
        std::cout << "Waiting ....." << std::endl;
        accepter();
        std::cout << 1 << std::endl;
        handler();
        std::cout << 2 << std::endl;
        responder();
        std::cout << 3 << std::endl;
        std::cout << "Success ....." << std::endl;
    }
}
