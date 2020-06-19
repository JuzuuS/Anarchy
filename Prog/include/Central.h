#ifndef CENTRAL_H
#define CENTRAL_H

#include <Processor.h>

using namespace PR;

namespace CENTRAL{

class Central : public Processor
{
    public:
        Central();

        void SetCash();
        float GetCash();



    protected:
        float Cash;

    //private:
};
}

#endif // CENTRAL_H
