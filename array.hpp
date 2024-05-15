#pragma once
#include "Element.h"
#include <iostream>
#include <climits>

template <typename T>
class Array_PQ
{

private:
    Element<T> *array;
    unsigned size;
    unsigned capacity;

public:
    /*
        KONSTRUKTORY I DESTRUKTOR
    */
    // konstruktor pozwalajacy na okreslenie pojemnosci tablicy na starcie
    Array_PQ(unsigned cap) : size{0}, capacity{cap}
    {
        array = new Element<T>[capacity];
    }

    // drugi konstruktor domyslnie ustawia pojemnosc na 5
    Array_PQ() : size{0}, capacity{5}
    {
        array = new Element<T>[capacity];
    }

    ~Array_PQ()
    {
        delete[] array;
    }

    /*
        OPERACJE DO ZBADANIA
    */

    void insert(int p, T e)
    {
        // dodanie wartosci na koncu
        if (size == capacity)
            doubleSize();
        Element<T> el(p, e);
        array[size] = el;
        size++;

        // przeniesienie jej w odpowiednie miejsce
        for (int i = size - 1; i > 0; i--)
        {
            if (p > array[i - 1].key)
            {
                swap(i, i - 1);
            }
            else
                return;
        }
    }

    Element<T> extractMax()
    {
        Element<T> temp = array[0];
        removeBeginning();
        return temp;
    }

    Element<T> peek()
    {
        return array[0];
    }

    void modifyKey(unsigned int p, T e)
    {

        for (int i = 0; i < size; i++)
        {
            // szukanie wartosci podanej na wejsciu
            if (array[i].value == e)
            {
                array[i].key = p;
                if (p > array[i - 1].key)
                {
                    
                    while (!((p <= array[i - 1].key && p > array[i + 1].key) || (i == 0)))
                    {
                        swap(i, i - 1);
                        i--;
                    }
                }
                else if (p < array[i + 1].key)
                {
                    while (!((p <= array[i - 1].key && p > array[i + 1].key) || (i == size - 1)))
                    {
                        swap(i, i + 1);
                        i++;
                    }
                }
                return;
            }
        }
    }

    int returnSize()
    {
        return size;
    }


    /*
        DODAWANIE DO TABLICY; NA POCZATKU I NA KONCU
    */

    void addEnd(int key, T value)
    {
        if (size == capacity)
            doubleSize();
        Element<T> el(key, value);
        array[size] = el;
        size++;
    }

    void addBeginning(int key, T value)
    {

        // zwiekszenie rozmiaru w przypadku przekroczenia zakresu
        if (size == capacity)
            doubleSize();

        // petla odpowiedzialna za zrobienie miejsca w tablicy dla nowego elementu
        for (int i = size - 1; i >= 0; i--)
        {
            array[i + 1] = array[i];
        }

        Element<T> el(key, value);

        // dodanie nowego elementu i inkrementacja zmiennej przechowywującej informacje o rozmiarze
        array[0] = el;
        size++;
    }

    // funkcja pomocnicza dla dodawania elementow - zwiekszanie pojemnosci tablicy dwukrotnie w przypadku braku miejsca

    void doubleSize()
    {
        capacity *= 2;
        Element<T> *temp = new Element<T>[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }

    /*
        USUWANIE NA POCZATKU I NA KONCU
    */

    void removeBeginning()
    {
        // zabezpieczenie przed proba usuniecia z pustej struktury
        if (size == 0)
        {
            std::cout << "struktura juz jest pusta\n";
            return;
        }

        // zastepywanie kazdego elementu wartoscia nastepnego; jesli rozmiar jest równy 1 to funkcja removeBeginning przejdzie od
        // razu do wywolania reomveEnd - jedyny elemeny tablicy jest również ostatnim
        if (size > 1)
        {
            for (int i = 1; i < size; i++)
                array[i - 1] = array[i];
        }

        // usuwanie ostatniego elementu (jego kopia jest elementem przedostatnim)
        removeEnd();
        // dekrementacja zmiennej size zawiera sie w tej funkcji
    }

    void removeEnd()
    {

        // zabezpieczenie przed proba usuniecia z pustej struktury
        if (size == 0)
        {
            std::cout << "struktura juz jest pusta\n";
            return;
        }

        // stworzenie nowej tablicy o takiej samej pojemnosci co stara
        Element<T> *temp = new Element<T>[capacity];

        // przeniesienie do nowej tablicy wszystkie elementy poza ostatnim
        for (int i = 0; i < size - 1; i++)
        {
            temp[i] = array[i];
        }

        // usuniecie starej tablicy i zmiana nazwy nowej
        delete[] array;
        array = temp;

        // dekrementacja zmiennej przechowywującej informacje o rozmiarze
        size--;
    }

    /*
        FUNKCJA ZWRACAJACA ELEMENT NA DANYM INDEKSIE
    */



    /*
        POMOCNICZA FUNKCJA DO WIZUALIZACJI ELEMENTOW
    */
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "[ klucz: " << array[i].key << ", wartość: " << array[i].value << " ]";
        }
        std::cout << std::endl;
    }

    // pomocnicza funkcja do zamieniania elementó w tablicy
    void swap(int id_1, int id_2)
    {
        Element<T> bufor = array[id_1];
        array[id_1] = array[id_2];
        array[id_2] = bufor;
    }

    void newCap(unsigned newCap)
    {
        capacity = newCap;
        Element<T> *temp = new Element<T>[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
};