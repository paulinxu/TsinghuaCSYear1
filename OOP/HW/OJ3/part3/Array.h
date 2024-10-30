#pragma once
#include "Node.h"

class Array
{
    int len;
    Node *arr;

    public:
    Array(int len);
    Array(const Array& x);
    Array(Array&& x);

    Node& operator[] (int i);
    Node operator[](int i) const;

    void operator=(const Array& x);
    Array& operator=(Array&& other);

    ~Array();

};