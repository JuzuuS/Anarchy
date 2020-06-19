#ifndef DESKTOP_H
#define DESKTOP_H

#include <Central.h>
using namespace CENTRAL;

namespace DESKTOP{

class Desktop : public Central
{
    public:
        Desktop();
        void SetAll();

        void SetMemType();
        const char* GetMemType();

        friend std::ostream & operator << (std::ostream &out, Desktop &d)
        {
            out << "\n���: " << d.GetName ()
            << "\n���-�� ����������: " << d.GetCores ()
            << "\n�������� ���������: " << d.GetTDP ()
            << "\n������� ���������: " << d.GetFreq ()
            << "\n������ ���������: " << d.GetCash ()
            << "\n���� ������ �������: " << d.GetMemType ();

            return out;
        }



    protected:
        char MemType[10];

   // private:
};
}

#endif // DESKTOP_H
