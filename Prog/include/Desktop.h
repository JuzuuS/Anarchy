#ifndef DESKTOP_H
#define DESKTOP_H

#include <Central.h>
using namespace CENTRAL;

namespace DESKTOP{

class Desktop : public Central
{
    public:
        Desktop();
        void SetAll();

        void SetMemType();
        const char* GetMemType();

        friend std::ostream & operator << (std::ostream &out, Desktop &d)
        {
            out << "\nИмя: " << d.GetName ()
            << "\nКол-во параметров: " << d.GetCores ()
            << "\nТочность измерения: " << d.GetTDP ()
            << "\nЕденицы измерения: " << d.GetFreq ()
            << "\nПредел измерения: " << d.GetCash ()
            << "\nЦена одного деления: " << d.GetMemType ();

            return out;
        }



    protected:
        char MemType[10];

   // private:
};
}

#endif // DESKTOP_H
