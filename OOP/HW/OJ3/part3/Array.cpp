#include "Array.h"
#include "Node.h"
#include <iostream>


Array::Array(int len) : len(len) 
{
    arr = new Node[len];
};
Array::Array(const Array& x)
{
    arr = new Node[x.len];
    for (int i = 0 ; i < x.len ; i ++)
    {
        arr[i] = x.arr[i];
    }
}
Array::Array(Array&& x) : arr(x.arr)
{
    x.arr = nullptr;
};

Array::~Array()
{
    delete[] arr;
}

Node &Array::operator[] (int i)
{
    return arr[i];
};

Node Array::operator[](int i) const
{
    return arr[i];
}

void Array::operator=(const Array& x)
{
    for (int i = 0 ; i < x.len ; i ++)
    {
        arr[i] = x.arr[i];
    }
}

Array& Array::operator=(Array&& other)
{
    if (this != &other)
    {
        delete[] arr;
        arr = other.arr;
        other.arr = nullptr;
    }
    return *this;
};
