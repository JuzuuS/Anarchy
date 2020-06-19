#include "Desktop.h"
#include <string.h>


namespace DESKTOP{
Desktop::Desktop()
{
    strcpy (MemType, "---");
}
void Desktop::SetAll(){
    SetName();
    SetCores();
    SetTDP();
    SetFreq();
    SetCash();
    SetMemType();
}

void Desktop::SetMemType(){
    std::cout << "Введите тип оперативной памяти: ";
    std::cin >> MemType;
}

const char* Desktop::GetMemType(){
    const char* memtype;
    memtype = MemType;
    return MemType;
}
}

