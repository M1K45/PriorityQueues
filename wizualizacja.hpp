#pragma once

#include "Element.h"
#include <iostream>
#include "array.hpp"
#include "heap.hpp"

void wizualizacja()
{
    std::cout << "#1 Implementacja kolejki priorytetowej na tablicy:\n\n";

    Array_PQ<char> array(10);
    std::cout << "a) funkcja insert:\n";
    array.insert(10, 'M');
    array.display();
    array.insert(5, 'i');
    array.display();
    array.insert(10, 'c');
    array.display();
    array.insert(2, 'h');
    array.display();
    array.insert(14, 'a');
    array.display();
    array.insert(8, 'l');
    array.display();
    std::cout << std::endl;

    std::cout << "b) funkcja extract:\n";
    std::cout << "Przed usunieciem:\n";
    array.display();
    Element<char> fooArr = array.extractMax();
    std::cout << "\nPo usunieciu:\n";
    array.display();
    std::cout << "usuniety element: [ klucz: " << fooArr.key << ", wartość: " << fooArr.value << " ]";

    std::cout << "\n\nc) funkcja modify:\n";
    std::cout << "Przed użyciem:\n";
    array.display();
    array.modifyKey(100, 'h');
    std::cout << "Po użyciu:\n";
    array.display();

    std::cout << "\nd) funkcja peek: [ klucz: " << array.peek().key << ", wartość: " << array.peek().value << " ]\n";

    std::cout << "\ne) funkcja size:\n";
    std::cout << "Rozmiar kolejki wynosi: " << array.returnSize();

    std::cout << std::endl
              << std::endl;

    std::cout << "#2 Implementacja kolejki priorytetowej na kopcu:\n\n";

    Heap_PQ<char> heap(10);
    std::cout << "a) funkcja insert:\n";
    heap.insert(10, 'M');
    heap.display();
    heap.insert(5, 'i');
    heap.display();
    heap.insert(10, 'c');
    heap.display();
    heap.insert(2, 'h');
    heap.display();
    heap.insert(14, 'a');
    heap.display();
    heap.insert(8, 'l');
    heap.display();
    std::cout << std::endl;

    std::cout << "b) funkcja extract:\n";
    std::cout << "Przed usunieciem:\n";
    heap.display();
    Element<char> fooHeap = heap.extractMax();
    std::cout << "Po usunieciu:\n";
    heap.display();
    std::cout << "usuniety element: [ klucz: " << fooHeap.key << ", wartość: " << fooHeap.value << " ]";

    std::cout << "\n\nc) funkcja modify:\n";
    std::cout << "Przed użyciem:\n";
    heap.display();
    heap.modifyKey(100, 'h');
    std::cout << "Po użyciu:\n";
    heap.display();

    std::cout << "\nd) funkcja peek: [ klucz: " << heap.peek().key << ", wartość: " << heap.peek().value << " ]\n";

    std::cout << "\ne) funkcja size:\n";
    std::cout << "Rozmiar kolejki wynosi: " << heap.returnSize() << std::endl;
}