#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <stdio.h>

#include "SimpleServer.h"

namespace SL{
    class TestServer: public SimpleServer{
        private:
            void accepter();
            void handler();
            void responder();
            char buffer [30000];
            int new_socket;

        public:
            TestServer();
            void launch();
    };
}

#endif