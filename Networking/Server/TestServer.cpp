#include "TestServer.h"
#include <cstring>
#include <fstream>   
#include <sstream>

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
    // std::string body = "<h1>Hello, this is me writing html stuff Signed Scott Le</h1>";
    // std::string http_response = "HTTP/1.1 200 OK\r\n"
    //     "Content-Type: text/html\r\n"
    //     "Content-Length: " + std::to_string(body.length()) + "\r\n"
    //     "\r\n" + 
    //     body;
    


    //write(new_socket, http_response.c_str(), http_response.length());
    std::string file_path = "index.html";
    std::ifstream html_file(file_path);
    std::string body;

    if (html_file){
        std::stringstream buffer;
        buffer << html_file.rdbuf();
        body = buffer.str();

        std::string http_response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: " + std::to_string(body.length()) + "\r\n"
            "\r\n" +
            body;
        write(new_socket, http_response.c_str(), http_response.length());
    }
    
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
