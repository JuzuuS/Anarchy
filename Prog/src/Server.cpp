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

void Server::GetAll(){
    GetName();
    GetCores();
    GetTDP();
    GetFreq();
    GetCash();
    GetMemChannels();
}

int Server::GetMemChannels(){
    return MemChannels;
}

void Server::SetMemChannels(){
    std::cout << "Введите количество каналов памяти: ";
    std::cin >> MemChannels;
}

}
