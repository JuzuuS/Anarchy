#include "DX.h"

using namespace GRAPHIC;

namespace dx {

DX::DX()
{
    DXVersion = 0;
}

void DX::SetAll(){
    SetName();
    SetCores();
    SetTDP();
    SetFreq();
    SetGMemory();
    SetDXVersion();
}

void DX::SetDXVersion(){
    std::cout << "¬ведите версию DirectX: ";
    std::cin >> DXVersion;
}
float DX::GetDXVersion(){
    return DXVersion;
}

}
