#include "Central.h"
#include <iostream>

namespace CENTRAL{
Central::Central(){
    Cash = 0;
}

void Central::SetCash(){
    std::cout << "Введите количество кэша: ";
    std::cin >> Cash;
}
float Central::GetCash(){
    return Cash;
}

}
