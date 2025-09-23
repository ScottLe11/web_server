#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <stdio.h>

//#include "../Sockets/ListeningSocket.cpp"
//top level libraries, gets access to all sockets
#include "../SL-Networking.h"
#include <unistd.h>

namespace SL{
    class SimpleServer{
        private:
            ListeningSocket * socket;
            virtual void accepter() = 0;
            virtual void handler() = 0;
            virtual void responder() = 0;
        
        public:
            SimpleServer(int domain, int service, int protocol,
                 int port, u_long interface, int bklg);
            
            virtual void launch() = 0;
            ListeningSocket * getSocket();
            

    };

}

#endif