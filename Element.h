#pragma once
#include <climits> 

template <typename T> 
// struktura elementu kolejki: para klucz - vartość
struct Element { 
public: 
    T value;
    int key;

    Element(int k, T v): key(k), value(v){}
    Element(): key(INT_MIN), value(T()){}
};
