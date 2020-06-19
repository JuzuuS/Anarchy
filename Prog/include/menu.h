#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <windows.h>
#include "fstream"
#include <iomanip>
#include <math.h>

#include "List.h"
//#include <List.cpp>
#include "Processor.h"
#include "Graphic.h"
#include "Central.h"
#include "RTX.h"
#include "DX.h"
#include "Desktop.h"
#include "Server.h"

using namespace PR;
using namespace DESKTOP;
using namespace SERVER;
using namespace rtx;
using namespace dx;
using namespace LST;

namespace MENU
{


class menu
{
    public:
        menu();
        void Display (List <Desktop> ru, List <Server> tr, List <RTX> vm, List <DX> am);
        void Menu ();
        void ClassChoice ();
        int GetFileSize (char Namef[50]);
        //~menu();
};

}

#endif // MENU_
