#include "ConnectingSocket.h"

SL::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface):
SimpleSocket(domain, service, protocol, port, interface){
    // set_connection(establish_connection_network(get_sock(), get_address()));
    // test_connection(get_connection());
    int connection = establish_connection_network(get_sock(), get_address());
    test_connection(connection);

}   


int SL::ConnectingSocket::establish_connection_network(int sock, struct sockaddr_in address){
    return connect(sock, (struct sockaddr *) &address, sizeof (address));
}