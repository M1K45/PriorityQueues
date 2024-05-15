#pragma once

#include "Element.h"
#include <iostream>
#include <cstdlib>
#include "array.hpp"
#include "heap.hpp"
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <math.h>
#include <time.h>

/*
    FUNKCJE POMIAROWE DLA OPERACJI INSERT
*/

void ArrayInsertMeasure(int measuringPoint)
{
    // 10 instancji
    Array_PQ<char> queue[10];
    clock_t start, stop;
    double duration;
    double srednia = 0;
    std::ofstream file;

    std::cout << "wykonywanie operacji insert dla kolejki opratej na tablicy, dla " << measuringPoint << " elementow\n";

    file.open("pomiary_tablica.csv", std::ios::app);
    file << "Czasy wykonania operacji insert dla kolejki opartej na tablicy, dla punktu pomierowego: " << measuringPoint << std::endl;

    for (int j = 0; j < 10; j++)
    {
        // ziarno dla wartosci punktu pomiarowego
        srand(j + 1); // ustawienie ziarna dla wypelniania struktury wybraną iloscią liczb

        // wypełnianie struktury
        for (int i = 0; i < measuringPoint; i++)
        {
            queue[j].insert(rand() % (5 * measuringPoint), 97 + rand() % 26);
        }

        srand(11); // osobne ziarno dla liczb dodawanych do struktury
        for (int k = 0; k < 4; k++)
        {
            // odmierzanie czasu
            start = clock();

            // badana operacja
            queue[j].insert(rand() % (5 * measuringPoint), 97 + rand() % 26);

            duration = clock() - start;

            // dodajemy czasy, aby potem wyciagnac z nich srednia
            srednia += duration;
            // Usunięcie jednego z elementów, aby następna operacja mogla byc wykonana na kolejce o takim samym rozmiarze, co na poczatku
            queue[j].removeEnd();
        }
    }
    // obliczanie sredniej, z 40 (4*10) pomiarow, wynik w milisekundach (10^-6)

    srednia /= 40;
    file << "srednia: \n " << (srednia / CLOCKS_PER_SEC) * pow(10, 6) << std::endl;
}

void HeapInsertMeasure(int measuringPoint)
{
    // 10 instancji
    Heap_PQ<char> queue[10];
    clock_t start, stop;
    double duration;
    double srednia = 0;
    std::ofstream file;

    std::cout << "wykonywanie operacji insert dla kolejki opratej na kopcu, dla " << measuringPoint << " elementow\n";

    file.open("pomiary_kopiec.csv", std::ios::app);
    file << "Czasy wykonania operacji insert dla kolejki opartej na kopcu, dla punktu pomierowego: " << measuringPoint << std::endl;

    for (int j = 0; j < 10; j++)
    {
        // ziarno dla wartosci punktu pomiarowego
        srand(j + 1); // ustawienie ziarna dla wypelniania struktury wybraną iloscią liczb

        // wypełnianie struktury
        for (int i = 0; i < measuringPoint; i++)
        {
            queue[j].insert(rand() % (5 * measuringPoint), 97 + rand() % 26);
        }

        srand(11); // osobne ziarno dla liczb dodawanych do struktury
        for (int k = 0; k < 4; k++)
        {
            // odmierzanie czasu
            start = clock();

            // badana operacja
            queue[j].insert(rand() % (5 * measuringPoint), 97 + rand() % 26);

            duration = clock() - start;

            // dodajemy czasy, aby potem wyciagnac z nich srednia
            srednia += duration;
            // Usunięcie jednego z elementów, aby następna operacja mogla byc wykonana na kolejce o takim samym rozmiarze, co na poczatku
            queue[j].extractMax();
        }
    }
    // obliczanie sredniej, z 40 (4*10) pomiarow, wynik w milisekundach (10^-6)

    srednia /= 40;
    file << "srednia: \n " << (srednia / CLOCKS_PER_SEC) * pow(10, 6) << std::endl;
}