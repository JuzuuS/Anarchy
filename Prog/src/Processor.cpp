#include <iostream>
#include "Processor.h"
#include <string.h>
#include <iomanip>

namespace PR{
Processor::Processor()
    {
        strcpy (Name, "---");
        Cores = 0;
        TDP = 0;
    }

void Processor::SetName(){
    std::cout << "������� �������� ����������: ";
    std::cin >> Name;
}
const char* Processor::GetName(){
    const char* name;
    name = Name;
    return name;
}

void Processor::SetCores(){
    std::cout << "������� ���������� ����: ";
    std::cin >> Cores;
}
int Processor::GetCores(){
    return Cores;
}

void Processor::SetTDP(){
    std::cout << "������� ����������: ";
    std::cin >> TDP;
}
float Processor::GetTDP(){
    return TDP;
}

void Processor::SetFreq(){
    std::cout << "������� �������: ";
    std::cin >> Frequency;
}
float Processor::GetFreq(){
    return Frequency;
}
}

//void Processor::fileOut(){
//        ofstream fout("file.txt");
//        fout <<"��� ������:" << modelName << " ������ ������:" << task <<" ���������� ����:"<< cores;
//        fout.close();
//    }
//
//void Processor::fileIn(){
//        char buff[50];
//        ifstream fin("file.txt");
//        if (!fin.is_open())
//            cout << "���� �� ������" << endl;
//        else {
//        fin.getline(buff, 100);
//        fin.close();
//        cout << buff << endl;
//        }
//    }
//
//void Processor::getInfo(){
//        cout <<"��� ������: " << modelName << endl;
//        cout <<"������ ������: " << task << endl;
//        cout <<"���������� ����: "<< cores << endl;
//    }

