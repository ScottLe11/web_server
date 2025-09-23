#ifndef BINDINGSOCKET_H
#define BINDINGSOCKET_H

#include <stdio.h>
#include "SimpleSocket.h"

namespace SL{
    //Constructor
    class BindingSocket: public SimpleSocket{
        public:
            BindingSocket(int domain, int service, int protocol,
                 int port, u_long interface);

            int establish_connection_network(int sock, struct sockaddr_in address);

            
    };

}


#endif