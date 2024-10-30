#include "polygon.h"
#include <cmath>

double Polygon::perimeter() const
{
    return n*s;
}

double Polygon::area() const
{
    return (n*s*s)/(4 * tan(PI/n));
}