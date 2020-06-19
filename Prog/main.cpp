#include <fstream>
#include <iostream>
#include <iomanip>
#include <windows.h>

#include "menu.h"

using namespace MENU;

int main()
{
    //SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    menu m;

    List <Desktop> desklst;
    List <Server> servlst;
    List <RTX> rtxlst;
    List <DX> dxlst;

    m.Display (desklst, servlst, rtxlst, dxlst);

    system ("pause");

    return 0;
}
