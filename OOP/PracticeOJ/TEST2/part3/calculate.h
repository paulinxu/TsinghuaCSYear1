#pragma once
#include "Fraction.h"

template <typename T>
T calculate(char expressionType, int x, int y, int z)
{
    if (expressionType == 'A')
    {
        return T(x)*T(x)+T(y)*T(y)+T(z)*T(z);
    }
    else if (expressionType == 'B')
    {
        return T(x)*T(y)+T(y)/T(z)-T(x)*T(z);
    }
    else
    {
        return T(y)*3*T(z)-T(x)*T(z)/(T(y)-2)-T(x)*T(y)/(T(z)+1);
    }
}