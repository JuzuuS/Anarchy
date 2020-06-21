#include "menu.h"

namespace MENU{
menu::menu(){}

void menu::Display (List <Desktop> ru, List <Server> tr, List <RTX> vm, List <DX> am)
{
    int number, choice = -1;

    Desktop desk;
    Server serv;
    RTX rtx;
    DX dx;

    Menu ();
    std::cout << "Введите выбранный номер: ";
    std::cin >> number; /// Переменная выбора меню

    while (number != 9)
    {
        if (number == 1)                                                       /// Создание элемента списка
        {
            ClassChoice ();
            std::cout << "Выберите заполняемый объект: ";
            std::cin >> choice; /// Переменная выбора класса
            std::cout << std::endl;

            if (choice == 1)
            {
                desk.SetAll ();
                ru.push_back (desk);
            }

            if (choice == 2)
            {
                serv.SetAll ();
                tr.push_back (serv);
            }

            if (choice == 3)
            {
                rtx.SetAll ();
                vm.push_back (rtx);
            }

            if (choice == 4)
            {
                dx.SetAll ();
                am.push_back (dx);
            }
        }

        if (number == 2)                                                        /// Очистка списка
        {
            if (choice == -1)
            {
                std::cout << "Список не создан" << std::endl << std::endl;
            }
            else
            {
                ru.ClearList ();
                tr.ClearList ();
                vm.ClearList ();
                am.ClearList ();
                std::cout << "Список очищен" << std::endl << std::endl;
            }
        }

        if (number == 3)                                                       /// Вывод списка на экран
        {
            if ((ru.GetSize () == 0) && (tr.GetSize () == 0) && (vm.GetSize () == 0) && (am.GetSize () == 0))
            {
                std::cout << "Список пуст" << std::endl << std::endl;
            }
            else
            {
                std::cout << "Список: " << std::endl;
                ru.GetList ();
                tr.GetList ();
                vm.GetList ();
                am.GetList ();
            }
        }

        if (number == 4)                                                            /// Сохранение списка в файл
        {

            if (choice == -1)
            {
                std::cout << "Список не создан" << std::endl << std::endl;
            }
            else
            {
                char Namef[50];
                std::cout << "Введите имя файла и его расширение: ";
                std::cin >> Namef;

                ru.SaveList (ru, Namef);
                tr.SaveList (tr, Namef);
                vm.SaveList (vm, Namef);
                am.SaveList (am, Namef);

                std::cout << "Список сохранен" << std::endl << std::endl;
            }
        }

        if (number == 5)                                                          /// Загрузка списка из файла
        {
            std::cout << "1. Загрузить все списки" << std::endl;
            std::cout << "2. Загрузить один список" << std::endl << std::endl;
            std::cin >> choice;

            if (choice == 1)    /// Загрузка всех списков
            {
                char Namef [50];
                const int N = 10;
                int Weight[N],  /// Массив веса списка
                i,  /// Счетчик массива
                FileSize,   /// Размер файла
                AllList;    /// Сколько списков в одном файле
                Weight[0] = 52;

                std::cout << "Введите имя файла и его расширение: ";
                std::cin >> Namef;

                FileSize = GetFileSize (Namef);
                AllList = FileSize / 52;

                for (i = 1; i <= AllList; i++)
                {
                    Weight[i] = ru.SearchName (ru, Namef, Weight, i);
                }

                i = 1; AllList = 0;
                while ((FileSize > 51) && (i <= N))
                {
                    FileSize = FileSize - Weight[i];
                    i++;
                    AllList++;
                }

                for (i = 1; i <= AllList; i++)
                {
                    if (Weight[i] == 80)
                    {
                        ru.LoadOneList (ru, Namef, Weight, i);
                    }
                    if (Weight[i] == 68)
                    {
                        tr.LoadOneList (tr, Namef, Weight, i);
                    }
                    if (Weight[i] == 52)
                    {
                        vm.LoadOneList (vm, Namef, Weight, i);
                    }
                    if (Weight[i] == 56)
                    {
                        am.LoadOneList (am, Namef, Weight, i);
                    }
                }
                std::cout << "Список загружен" << std::endl << std::endl;
            }
            if (choice == 2)    /// Загрузка одного списка
            {
                ClassChoice ();

                std::cout << "Введите номер класса, в который нужно загрузить список: ";
                std::cin >> choice;
                std::cout << std::endl;

                char Namef[50];
                const int N = 20;
                int Weight[N], i, num;
                Weight[0] = 25;

                std::cout << "Введите имя файла и его расширение: ";
                std::cin >> Namef;

                std::cout << "Введите номер списка: ";
                std::cin >> num;

                for (i = 1; i <= num; i++)
                {
                    Weight[i] = ru.SearchName (ru, Namef, Weight, i);
                }

                if (choice == 1)
                {
                    ru.LoadOneList (ru, Namef, Weight, num);
                    std::cout << "Список загружен" << std::endl << std::endl;
                }
                if (choice == 2)
                {
                    tr.LoadOneList (tr, Namef, Weight, num);
                    std::cout << "Список загружен" << std::endl << std::endl;
                }
                if (choice == 3)
                {
                    vm.LoadOneList (vm, Namef, Weight, num);
                    std::cout << "Список загружен" << std::endl << std::endl;
                }
                if (choice == 4)
                {
                    am.LoadOneList (am, Namef, Weight, num);
                    std::cout << "Список загружен" << std::endl << std::endl;
                }
            }
        }

        if (number == 6)                                                                        /// Найти список
        {
            if ((ru.GetSize () == 0) && (tr.GetSize () == 0) && (vm.GetSize () == 0) && (am.GetSize () == 0))
            {
                std::cout << "Список пуст" << std::endl << std::endl;
            }
            else
            {
                int num;

                std::cout << "Введите номер экземпляра: ";
                std::cin >> num;

                if ((ru.GetSize () >= num) && (num > 0))
                    ru.FindList (num);

                if ((ru.GetSize () < num) && (tr.GetSize () + ru.GetSize () >= num))
                    tr.FindList (abs (ru.GetSize () - num));

                if ((tr.GetSize () + ru.GetSize () < num) && (tr.GetSize () + ru.GetSize () + vm.GetSize () >= num))
                    vm.FindList (abs (tr.GetSize () + ru.GetSize () - num));

                if ((tr.GetSize () + ru.GetSize () + vm.GetSize () < num) && (tr.GetSize () + ru.GetSize () + vm.GetSize () + am.GetSize () >= num))
                    am.FindList (abs (tr.GetSize () + ru.GetSize () + vm.GetSize () - num));

                if ((num <= 0) || (tr.GetSize () + ru.GetSize () + vm.GetSize () + am.GetSize () < num))
                    std::cout << "Такого списка нет" << std::endl << std::endl;
            }
        }

        if (number == 7)                                                                       /// Удаление экземпляра
        {
            ClassChoice ();

            std::cout << "Введите номер класса, в котором нужно удалить последний список: ";
            std::cin >> choice;
            std::cout << std::endl;

            if (choice == 1)
            {
                if (ru.GetSize () != 0)
                    ru.pop_back ();
                else
                    std::cout << "Список пуст" << std::endl << std::endl;
            }
            if (choice == 2)
            {
                if (tr.GetSize () != 0)
                    tr.pop_back ();
                else
                    std::cout << "Список пуст" << std::endl << std::endl;
            }
            if (choice == 3)
            {
                if (vm.GetSize () != 0)
                    vm.pop_back ();
                else
                    std::cout << "Список пуст" << std::endl << std::endl;
            }
            if (choice == 4)
            {
                if (am.GetSize () != 0)
                    am.pop_back ();
                else
                    std::cout << "Список пуст" << std::endl << std::endl;
            }
        }

        if (number == 8)                                                        /// Очистка экрана консоли
            system ("cls");

        if ((number < 1) || (number > 9))                                       /// Выход за границы меню
            std::cout << "Введите число от 1 до 9" << std::endl << std::endl;

        Menu ();
        std::cout << "Введите выбраный номер: ";
        std::cin >> number;
    }
}

void menu::Menu ()                                                                                       /// Menu
{
    std::cout << "Меню: " << std::endl;
    std::cout << "1. Создать элемент списка" << std::endl;
    std::cout << "2. Очистить список" << std::endl;
    std::cout << "3. Вывести список на экран" << std::endl;
    std::cout << "4. Сохранить список в файл" << std::endl;
    std::cout << "5. Загрузить список из файла" << std::endl;
    std::cout << "6. Найти список" << std::endl;
    std::cout << "7. Удалить экземпляр" << std::endl;
    std::cout << "8. Очистить экран консоли" << std::endl;
    std::cout << "9. Завершить работу программы" << std::endl << std::endl;
}

void menu::ClassChoice ()
{
    std::cout << "1. Домашний" << std::endl;
    std::cout << "2. Серверный" << std::endl;
    std::cout << "3. DX" << std::endl;
    std::cout << "4. RTX" << std::endl << std::endl;
}

int menu::GetFileSize (char Namef[50])
{
    const char* s;
    s = Namef;

    std::fstream f (s);
    int FileSize = 0;
    f.seekg (0, std::ios::end);
    FileSize = f.tellg ();
    f.close();

    return FileSize;
}

}
