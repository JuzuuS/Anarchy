#include "Graphic.h"
#include <iostream>

namespace GRAPHIC{

Graphic::Graphic()
{
   GMemory = 0;
}

void Graphic::SetGMemory(){
        std::cout << "Введите количество графической памяти: ";
        std::cin >> GMemory;
    }
float Graphic::GetGMemory(){
        return GetGMemory();
    }

}
