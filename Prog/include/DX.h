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
            out << "\n���: " << x.GetName ()
            << "\n���-�� ����: " << x.GetCores ()
            << "\n����������: " << x.GetTDP ()
            << "\n�������: " << x.GetFreq ()
            << "\n���-�� ������: " << x.GetGMemory ()
            << "\n������ DirectX: " << x.GetDXVersion ();

            return out;
        }


    private:
        float DXVersion;


    };
}

#endif // DX_H
