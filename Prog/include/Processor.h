#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>

namespace PR{


class Processor
{
    public:
        Processor();

        void SetName();
        const char* GetName();

        void SetCores();
        int GetCores();

        void SetTDP();
        float GetTDP();

        void SetFreq();
        float GetFreq();



    private:
        char Name[30];
        int Cores;
        float TDP;
        float Frequency;


    };
}

#endif PROCESSOR_H
