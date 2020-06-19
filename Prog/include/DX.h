#ifndef DX_H
#define DX_H

#include <Graphic.h>

using namespace GRAPHIC;

namespace dx{

class DX : public Graphic
{
    public:
        DX();

        void SetAll();

        void SetDXVersion();
        float GetDXVersion();

        friend std::ostream & operator << (std::ostream &out, DX &x)
        {
            out << "\nИмя: " << x.GetName ()
            << "\nКол-во параметров: " << x.GetCores ()
            << "\nТочность измерения: " << x.GetTDP ()
            << "\nЕденицы измерения: " << x.GetFreq ()
            << "\nПредел измерения: " << x.GetGMemory ()
            << "\nЦена одного деления: " << x.GetDXVersion ();

            return out;
        }



    protected:
        float DXVersion;



    //private:
};
}

#endif // DX_H
