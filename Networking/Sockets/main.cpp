#include "ListeningSocket.h"

int main(){
    std::cout << "Starting... " << std::endl;

    std::cout << "Binding Socket " << std::endl;
    SL::BindingSocket bs = SL::BindingSocket(AF_INET, SOCK_STREAM, 0 ,1025, INADDR_ANY);
    std::cout << "Listening Socket" << std::endl;
    SL::ListeningSocket ls = SL::ListeningSocket(AF_INET, SOCK_STREAM, 0 ,1024, INADDR_ANY, 10);
    std::cout << "Success" << std::endl;
}