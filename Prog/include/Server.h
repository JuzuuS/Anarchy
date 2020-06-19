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
            out << "\nИмя: " << s.GetName ()
            << "\nКол-во параметров: " << s.GetCores ()
            << "\nТочность измерения: " << s.GetTDP ()
            << "\nЕденицы измерения: " << s.GetFreq ()
            << "\nПредел измерения: " << s.GetCash ()
            << "\nЦена одного деления: " << s.GetMemChannels ();

            return out;
        }



    protected:
       int MemChannels;
    //private:
};
}
#endif // SERVER_H
