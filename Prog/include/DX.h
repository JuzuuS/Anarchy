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
        void GetAll();

        void SetDXVersion();
        float GetDXVersion();



        friend std::ostream& operator << (std::ostream &out, DX &x)
        {
            out << "\nИмя: " << x.GetName ()
            << "\nКол-во ядер: " << x.GetCores ()
            << "\nТеплопакет: " << x.GetTDP ()
            << "\nЧастота: " << x.GetFreq ()
            << "\nКол-во памяти: " << x.GetGMemory ()
            << "\nВерсия DirectX: " << x.GetDXVersion ();

            return out;
        }


    private:
        float DXVersion;


    };
}

#endif // DX_H
