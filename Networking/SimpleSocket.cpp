#include "SimpleSocket.h"


// Default constructor for Simple socket
SL::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){
    
    // Addr structure 
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    
    // connection established
    sock = socket(domain, service, protocol);
    test_connection(sock);

    connection = establish_connection_network(sock, address);
    test_connection(connection);
    
    // bind(connection, address, ) ;
};

// Test connection virtual function
void SL::SimpleSocket::test_connection(int test_item){
    if (test_item < 0){
        perror("Connection failed");
        exit(EXIT_FAILURE);
    } 

};


//Getter functions for private vals
struct sockaddr_in SL::SimpleSocket::get_address(){
    return address;
}

int SL::SimpleSocket::get_sock(){
    return sock;
}

int SL::SimpleSocket::get_connection(){
    return connection;
}