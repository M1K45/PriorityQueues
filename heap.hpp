#pragma once
#include "Element.h"
#include <iostream>
#include <climits>

template <typename T>
class Heap_PQ
{
public:
    Element<T> *array;
    int size;
    unsigned capacity;

    /*
        KONSTRUKTORY I DESTRUKTOR
    */
    // konstruktor pozwalajacy na okreslenie pojemnosci kopca na starcie
    Heap_PQ(unsigned cap) : size{0}, capacity{cap}
    {
        array = new Element<T>[capacity];
    }

    // drugi konstruktor domyslnie ustawia pojemnosc na 5
    Heap_PQ() : size{0}, capacity{5}
    {
        array = new Element<T>[capacity];
    }

    ~Heap_PQ()
    {
        delete[] array;
    }

    /*
        OPERACJE DO ZBADANIA
    */
    void insert(int p, T e)
    {
        if (size == capacity)
            doubleSize();

        size++;

        int i = size - 1;

        Element<T> el(p, e);

        array[i] = el;

        heapifyUp(i);
    }

    Element<T> extractMax()
    {

        Element<T> output = array[0];

        array[0] = array[size - 1];
        size--;
        heapifyDown(0);
        return output;
    }

    Element<T> peek()
    {
        return array[0];
    }

    void modifyKey(unsigned int p, T e)
    {
        // przeszukanie tablicy w celu znalezienia elementu o danym elemencie, poczynając od korzenia
        for (int i = 0; i < size; i++)
        {
            if (array[i].value == e)
            {
                array[i].key = p;

                if (p < array[left(i)].key || p < array[rigth(i)].key)
                {
                    heapifyDown(i);
                }
                if (p > array[parent(i)].key)
                {
                    heapifyUp(i);
                }
                break;
            }
        }
    }

    int returnSize()
    {
        return size;
    }

    // funkcja odpowiedzialna za zwiększanie pojemności w przypadku braku miejsca
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
        FUNKCJE ZWRACAJACE INDEKSY RODZICA, LEWEGO I PRAWEGO DZIECKA DLA ELEMENTU
        O ZADANYM INDEKSIE
    */

    int parent(int i)
    {
        if (i < 0)
        {
            return NULL;
        }
        return (i - 1) / 2;
    }

    int left(int i)
    {
        int temp = 2 * i + 1;
        if (temp >= size)
        {
            return NULL;
        }
        else
            return temp;
    }

    int rigth(int i)
    {
        int temp = 2 * i + 2;
        if (temp >= size)
        {
            return NULL;
        }
        else
            return temp;
    }
    /*
        KOPCOWANIA W GÓRĘ I W DÓŁ
    */

    void heapifyUp(int i)
    {
        while (i != 0 && array[parent(i)].key < array[i].key)
        {
            Element<T> bufor = array[i];
            array[i] = array[parent(i)];
            array[parent(i)] = bufor;
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int leftChild = left(i);

        int rigthChild = rigth(i);
   ;

        int maxValueIndex = i;

        if (leftChild < size && array[leftChild].key > array[i].key)
        {
            maxValueIndex = leftChild;
        }

        if (rigthChild < size && array[rigthChild].key > array[maxValueIndex].key)
        {
            maxValueIndex = rigthChild;
        }
        

        if (maxValueIndex != i)
        {
            Element<T> bufor = array[i];
            array[i] = array[maxValueIndex];
            array[maxValueIndex] = bufor;

            if (left(maxValueIndex) < size && left(maxValueIndex) > 0)
            {

                heapifyDown(maxValueIndex);
            }
        }
    }


    /*
        POMOCNICZA FUNKCJA DO WIZUALIZACJI ELEMENTOW
    */
    void display()
    {
        if (size == 0)
        {
            std::cout << "kopiec jest pusty\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            std::cout << "[ klucz: " << array[i].key << ", wartość: " << array[i].value << " ]";
        }
        std::cout << std::endl;
    }

};