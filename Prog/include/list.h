#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string.h>
#include "fstream"



namespace LST
{

template <typename T>
class List
{
    public:
        class Info
        {
            public:
                Info *pNew;
                T data;
                Info (T data, Info *pNew = NULL)
                {
                    this -> data = data;
                    this -> pNew = pNew;
                }
        };


        List ()
            {
                Size = 0;
                head = NULL;
            }

                                                                                   /// Push_back
    void push_back (T data)
            {
                if (head == NULL)
                {
                    head = new Info (data, NULL);
                }

        else
            {
                Info *current = this -> head;

        while (current -> pNew != NULL)
            {
                current = current -> pNew;
            }
            current -> pNew = new Info (data, NULL);
        }
        Size++;
        }

                                                                                    /// Pop_front
        void pop_front ()
            {
                Info *current = this -> head;

                head = current -> pNew;

                delete current;
                Size--;
            }

                                                                                    /// Pop_back
        void pop_back ()
            {
                Info *current = this -> head;

            if (Size == 1)
            {
                while (current -> pNew != NULL)
                    {
                    current = current -> pNew;
                    }

                current = NULL;
                delete current;
            }
            else
            {
                current = current -> pNew;

                Info *previous = this -> head;

            while (current -> pNew != NULL)
                {
                    current = current -> pNew;
                    previous = previous -> pNew;
                }

                current = NULL;
                previous -> pNew = NULL;
                delete current;
                }

                Size--;
                }

                                                                         /// GetList
void GetList ()
{
    Info *current = this -> head;
    int i;

    for (i = 0; i < Size; i++)
    {
        std::cout << current -> data << std::endl;
        current = current -> pNew;
    }
    std::cout << std::endl;
}


                                                                              /// ClearList
void ClearList ()
{
    int i;
    for (i = 0; i < Size; i++)
    {
        pop_back ();
    }

    Size = 0;
    head = NULL;
}

                                                                            /// SaveList
void SaveList (List <T> lst, char Namef[50])
{
    const char* s;

    s = Namef;

    Info* current = this -> head;
    std::ofstream f;
    f.open (s, std::ofstream::out | std::ofstream::app);
    if (current != NULL)
    {
        while (current != NULL)
        {
           f.write ((char*) &current -> data, sizeof (T));
           current = current -> pNew;
        }
        f.close ();
    }
}

                                                                          /// LoadOneList
int LoadOneList (List <T> &lst, char Namef[50], int weight[ ], int num)
{
    const char* s;
    int i;

    s = Namef;

    std::ifstream f;
    T type;
    f.open (s, std::ifstream::binary);

    if (!f.is_open ())
    {
        std::cout << "Ошибка открытия файла" << std::endl << std::endl;
        return 0;
    }
    else
    {
        for (i = 1; i <= num; i++)
            f.read ((char*) &type, weight[i]);

        push_back (type);
    }

    f.close ();
    return 1;
}

        int GetSize ()
        {return Size;}


int SearchName (List <T> &lst, char Namef[50], int weight[ ], int num)
{
    int i; /// Счётчик массива
    const char* s; s = Namef;
    char *tmp;

    std::ifstream f;
    T type;

    f.open (s, std::ifstream::binary);

    if (num == 1)
        f.read ((char*) &type, weight[0]);

    if (num > 1)
    {
        for (i = 1; i < num; i++)
            f.read ((char*) &type, weight[i]);

        f.read ((char*) &type, weight[0]);
    }

    for (i = 0; i < 5; i++)
        tmp = (char*) &type + i;

    f.close ();

    if (strstr (tmp, "Линейка") != NULL)
        return 80;

    if (strstr (tmp, "Транспортир") != NULL)
        return 68;

    if (strstr (tmp, "Вольтметр") != NULL)
        return 52;

    if (strstr (tmp, "Амперметр") != NULL)
        return 56;
}

                                                                                 /// FindList
void FindList (int num)
{
    Info* current = head;
    int i;

    for (i = 0; i < num - 1; i++)
    {
        current = current -> pNew;
    }
    std::cout << current -> data << std::endl;
    }
    private:
        int Size;
        Info *head;
    };
}

#endif // LIST_H
