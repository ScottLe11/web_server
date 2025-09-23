#include "BindingSocket.h" 

SL::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface):
SimpleSocket(domain, service, protocol, port, interface){
    set_connection(establish_connection_network(get_sock(), get_address()));
    test_connection(get_connection());

}


int SL::BindingSocket::establish_connection_network(int sock, struct sockaddr_in address){
    return bind(sock, (struct sockaddr *)& address, sizeof(address));
}