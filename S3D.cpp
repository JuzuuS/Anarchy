﻿
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
using namespace std;

#include <stdio.h>
#include <Windows.h>

int nScreenWidth = 120; // Ширина консольного окна
int nScreenHeight = 40; // Высота консольного окна

float fPlayerX = 1.0f; // Координата игрока по оси X
float fPlayerY = 1.0f; // Координата игрока по оси Y
float fPlayerA = 0.0f; // Направление игрока

int nMapHeight = 16; // Высота игрового поля
int nMapWidth = 16;  // Ширина игрового поля

float fFOV = 3.14159 / 3; // Угол обзора (поле видимости)
float fDepth = 30.0f;     // Максимальная дистанция обзора

vector <pair <float, float>> p;

int main()
{
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight + 1]; // Массив для записи в буфер
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // Буфер экрана
    SetConsoleActiveScreenBuffer(hConsole); // Настройка консоли
    DWORD dwBytesWritten = 0; // Для дебага

    wstring map; // Строковый массив
    map += L"################";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#..............#";
    map += L"################";

    auto tp1 = chrono::system_clock::now(); // Переменные для подсчета
    auto tp2 = chrono::system_clock::now(); // пройденного времени

    while (1) // Игровой цикл
    {
        tp2 = chrono::system_clock::now();
        chrono::duration <float> elapsedTime = tp2 - tp1;
        tp1 = tp2;
        float fElapsedTime = elapsedTime.count();

        if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
            fPlayerA -= (1.5f) * fElapsedTime; // Клавишей "A" поворачиваем по часовой стрелке

        if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
            fPlayerA += (1.5f) * fElapsedTime; // Клавишей "D" поворачиваем против часовой стрелки

        if (GetAsyncKeyState((unsigned short)'W') & 0x8000) // Клавишей "W" идём вперёд
        {
            fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
            fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;

            if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') { // Если столкнулись со стеной, но откатываем шаг
                fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
                fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
            }
        }

        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) // Клавишей "S" идём назад
        {
            fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
            fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
            if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') { // Если столкнулись со стеной, но откатываем шаг
                fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
                fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
            }
        }

        for (int x = 0; x < nScreenWidth; x++)  // Проходим по всем X
        {
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV; // Направление луча

            float fDistanceToWall = 0.0f; // Расстояние до препятствия в направлении fRayAngle
            bool bHitWall = false; // Достигнул ли луч стенку

            float fEyeX = sinf(fRayAngle); // Координаты единичного вектора fRayAngle
            float fEyeY = cosf(fRayAngle);

            while (!bHitWall && fDistanceToWall < fDepth) // Пока не столкнулись со стеной
            {                                                  // Или не вышли за радиус видимости
                fDistanceToWall += 0.1f;

                int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall); // Точка на игровом поле
                int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall); // в которую попал луч

                if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
                { // Если мы вышли за карту, то дальше смотреть нет смысла - фиксируем соударение на расстоянии видимости
                    bHitWall = true;
                    fDistanceToWall = fDepth;
                }
                else if (map[nTestY * nMapWidth + nTestX] == '#')
                { // Если встретили стену, то заканчиваем цикл
                    bHitWall = true;
                }
            }

            //Вычисляем координаты начала и конца стенки по формулам (1) и (2)
            int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
            int nFloor = nScreenHeight - nCeiling;

            short nShade;

            if (fDistanceToWall <= fDepth / 3.0f)        nShade = 0x2588; // Если стенка близко, то рисуем 
            else if (fDistanceToWall < fDepth / 2.0f)    nShade = 0x2593; // светлую полоску
            else if (fDistanceToWall < fDepth / 1.5f)    nShade = 0x2592; // Для отдалённых участков 
            else if (fDistanceToWall < fDepth)           nShade = 0x2591; // рисуем более темную
            else                                         nShade = ' ';

            for (int y = 0; y < nScreenHeight; y++)
            {
                if (y <= nCeiling)
                    screen[y * nScreenWidth + x] = ' ';
                else if (y > nCeiling&& y <= nFloor)
                    screen[y * nScreenWidth + x] = nShade;
                else
                {
                    // То же самое с полом - более близкие части рисуем более заметными символами
                    float b = 1.0f - ((float)y - nScreenHeight / 2.0) / ((float)nScreenHeight / 2.0);
                    if (b < 0.25)        nShade = '#';
                    else if (b < 0.5)    nShade = 'x';
                    else if (b < 0.75)   nShade = '~';
                    else if (b < 0.9)    nShade = '-';
                    else                 nShade = ' ';

                    screen[y * nScreenWidth + x] = nShade;
                }
            }
        }


        swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElapsedTime);// Display Stats

        /*for (int nx = 0; nx < nMapWidth; nx++)
            for (int ny = 0; ny < nMapWidth; ny++)
            {
                screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
            }
        //screen[((int)fPlayerX + 1) * nScreenWidth + (int)fPlayerY] = 'P'; // Display Map*/

        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten); // Display Frame
    }
        // Повторяющиеся действия

    return 0;
}
