#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>

namespace PR{


class Processor
{
    public:
        Processor();
       // virtual void SetAll ();

        void SetName();
        const char* GetName();

        void SetCores();
        int GetCores();

        void SetTDP();
        float GetTDP();

        void SetFreq();
        float GetFreq();



    protected:
        char Name[30];
        int Cores;
        float TDP;
        float Frequency;

    //private:
};
}

#endif PROCESSOR_H
