#ifndef SIMPLESOCKET_H
#define SIMPLESOCKET_H

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>


namespace SL {
    // Constructor    
    class SimpleSocket{
        private:
            struct sockaddr_in address;
            int sock;
            

        public:
            SimpleSocket(int domain, int service, int protocol, int port, u_long interface);

            virtual int establish_connection_network(int sock, struct sockaddr_in address) = 0;
            void test_connection(int);
            //Getters
            struct sockaddr_in get_address();
            int get_sock();
            int get_connection(); 
            //Setters
            void set_connection(int val);
    };

}

#endif