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
        void GetAll();

        void SetMemType();
        const char* GetMemType();

        friend std::ostream& operator << (std::ostream &out, Desktop &d)
        {
            out << "\nИмя: " << d.GetName ()
            << "\nКол-во ядер: " << d.GetCores ()
            << "\nТеплопакет: " << d.GetTDP ()
            << "\nЧастота: " << d.GetFreq ()
            << "\nКэш: " << d.GetCash ()
            << "\nТип Памяти: " << d.GetMemType ();

            return out;
        }



    private:
        char MemType[10];

};
}

#endif // DESKTOP_H
