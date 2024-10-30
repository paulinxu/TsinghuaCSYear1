#pragma once
#include <iostream>
#include "test.h"
#include <vector>
using namespace std;

class PyObject
{
    int i;
    char c;
    double d;
    Test *t;
    bool isTest;

    public:

    void operator = (int x) 
    { 
        i = x; 
        cout << "PyObject got a value" << endl;
        isTest = false;
    }
    void operator = (char x) 
    { 
        c = x; 
        cout << "PyObject got a value" << endl;
        isTest = false;
    }
    void operator = (double x) 
    { 
        d = x; 
        cout << "PyObject got a value" << endl;
        isTest = false;
    }
    void operator = (Test& x) 
    {
        cout << "PyObject got a value\nBorrowing" << endl;
        t = &x;
        isTest = true;
    }

    operator int() const { return i; }
    operator char() const { return c; }
    operator double() const { return d; }
    operator Test() const { return *t; }
};