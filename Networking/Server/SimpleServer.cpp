#include "SimpleServer.h"

SL::SimpleServer::SimpleServer(int domain, int service, int protocol,
int port, u_long interface, int bklg){
    socket = new ListeningSocket(domain, service, protocol,
    port, interface, bklg);
    
}

SL::ListeningSocket * SL::SimpleServer::getSocket(){
    return socket;
}