#ifndef RTX_H
#define RTX_H

#include "list.h"

#include <Graphic.h>


using namespace GRAPHIC;


namespace rtx{
class RTX : public Graphic
{
    public:
        RTX();
        void SetAll();
        void GetAll();

        void SetMemBus();
        int GetMemBus();

        friend std::ostream& operator << (std::ostream &out, RTX &r)
        {
            out << "\n���: " << r.GetName ()
            << "\n���-�� ����: " << r.GetCores ()
            << "\n����������: " << r.GetTDP ()
            << "\n�������: " << r.GetFreq ()
            << "\n���-�� ������: " << r.GetGMemory ()
            << "\n���������� �����������: " << r.GetMemBus ();

            return out;
        }



    private:
        int MemBus;

    //private:
    };
}

#endif // RTX_H
