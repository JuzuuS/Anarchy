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
        void GetAll();

        void SetMemChannels();
        int GetMemChannels();

        friend std::ostream& operator << (std::ostream &out, Server &s)
        {
            out << "\nИмя: " << s.GetName ()
            << "\nКол-во ядер: " << s.GetCores ()
            << "\nТеплопакет: " << s.GetTDP ()
            << "\nЧастота: " << s.GetFreq ()
            << "\nКэш: " << s.GetCash ()
            << "\nКаналы памяти: " << s.GetMemChannels ();

            return out;
        }


    private:
       int MemChannels;

    };
}
#endif // SERVER_H
