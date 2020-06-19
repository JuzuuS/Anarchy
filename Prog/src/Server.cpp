#include "Server.h"

namespace SERVER{

Server::Server()
{
    MemChannels = 0;
}

void Server::SetAll(){
    SetName();
    SetCores();
    SetTDP();
    SetFreq();
    SetCash();
    SetMemChannels();
}

int Server::GetMemChannels(){
    return MemChannels;
}

void Server::SetMemChannels(){
    std::cout << "Введите количество каналов памяти: ";
    std::cin >> MemChannels;
}

}
