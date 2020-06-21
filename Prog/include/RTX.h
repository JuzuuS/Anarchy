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
            out << "\nИмя: " << r.GetName ()
            << "\nКол-во ядер: " << r.GetCores ()
            << "\nТеплопакет: " << r.GetTDP ()
            << "\nЧастота: " << r.GetFreq ()
            << "\nКол-во памяти: " << r.GetGMemory ()
            << "\nПропускная способность: " << r.GetMemBus ();

            return out;
        }



    private:
        int MemBus;

    //private:
    };
}

#endif // RTX_H
