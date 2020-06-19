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

        void SetMemBus();
        int GetMemBus();

        friend std::ostream & operator << (std::ostream &out, RTX &r)
        {
            out << "\nИмя: " << r.GetName ()
            << "\nКол-во параметров: " << r.GetCores ()
            << "\nТочность измерения: " << r.GetTDP ()
            << "\nЕденицы измерения: " << r.GetFreq ()
            << "\nПредел измерения: " << r.GetGMemory ()
            << "\nЦена одного деления: " << r.GetMemBus ();

            return out;
        }



    protected:
        int MemBus;

    //private:
};
}

#endif // RTX_H
