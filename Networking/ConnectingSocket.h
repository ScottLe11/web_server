#ifndef CONNECTINGSOCKET_H
#define CONNECTINGSOCKET_H

#include <stdio.h>
#include "SimpleSocket.h"

namespace SL{

    class ConnectingSocket: public SimpleSocket{
        public:
            ConnectingSocket(int domain, int service, int protocol,
            int port, u_long interface);

            int establish_connection_network(int sock, struct sockaddr_in address);
    }; 
}

#endif