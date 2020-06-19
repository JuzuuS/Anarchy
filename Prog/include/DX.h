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
            out << "\n���: " << x.GetName ()
            << "\n���-�� ����������: " << x.GetCores ()
            << "\n�������� ���������: " << x.GetTDP ()
            << "\n������� ���������: " << x.GetFreq ()
            << "\n������ ���������: " << x.GetGMemory ()
            << "\n���� ������ �������: " << x.GetDXVersion ();

            return out;
        }



    protected:
        float DXVersion;



    //private:
};
}

#endif // DX_H
