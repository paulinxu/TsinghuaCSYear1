#ifndef zero
#define zero = 0.000001
#endif

#pragma once
#include <iostream>
#include <cmath>

// bool isEqual(double a, double b)
// {
//     return (abs(a-b) < 0.000001);
// }

using namespace std;
template <typename T>
class Line
{
    public:
    T k;
    T b = 0;
    Line(T k, T b) : k(k), b(b){};
    Line(T k) : k(k){};

    bool intersect(Line const& l)
    {
        if (abs(k-l.k) < 0.000001 && !(abs(b-l.b) < 0.000001))
        {
            return false;
        }
        return true;
    }
    void show()
    {
        cout << k << ',' << b << endl;
    }
    bool operator<(Line const &other)
    {
        return k < other.k;
    }
};