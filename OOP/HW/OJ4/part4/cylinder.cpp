#include "cylinder.h"

double Cylinder::area() const
{
    return (2*PI*r2*r2) + (2*PI*r2*h);
}

double Cylinder::volume() const
{
    return PI*r2*r2*h;
}