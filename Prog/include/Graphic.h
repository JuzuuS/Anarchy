#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <iostream>
#include <Processor.h>


using namespace PR;


namespace GRAPHIC{

class Graphic : public Processor
{
    public:
        Graphic();

        void SetGMemory();
        float GetGMemory();


    protected:
        float GMemory;

    //private:
};
}

#endif // GRAPHIC_H
