#ifndef SERVER_H
#define SERVER_H

#include <Central.h>

using namespace CENTRAL;

namespace SERVER{
class Server : public Central
{
    public:
        Server();
        void SetAll();

        void SetMemChannels();
        int GetMemChannels();

        friend std::ostream & operator << (std::ostream &out, Server &s)
        {
            out << "\n���: " << s.GetName ()
            << "\n���-�� ����������: " << s.GetCores ()
            << "\n�������� ���������: " << s.GetTDP ()
            << "\n������� ���������: " << s.GetFreq ()
            << "\n������ ���������: " << s.GetCash ()
            << "\n���� ������ �������: " << s.GetMemChannels ();

            return out;
        }



    protected:
       int MemChannels;
    //private:
};
}
#endif // SERVER_H
