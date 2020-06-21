#include "RTX.h"
namespace rtx{
RTX::RTX()
{
    MemBus = 0;
}

void RTX::SetAll(){
    SetName();
    SetCores();
    SetTDP();
    SetFreq();
    SetGMemory();
    SetMemBus();
}

void RTX::GetAll(){
    GetName();
    GetCores();
    GetTDP();
    GetFreq();
    GetGMemory();
    GetMemBus();
}

void RTX::SetMemBus(){
    std::cout << "¬ведите шину пам€ти: ";
    std::cin >> MemBus;
}
int RTX::GetMemBus(){
    return MemBus;
}
}
