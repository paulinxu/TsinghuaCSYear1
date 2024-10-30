#include "circle.h"

double Circle::perimeter() const
{
    return 2*PI*r;
}

double Circle::area() const
{
    return PI*r*r;
}