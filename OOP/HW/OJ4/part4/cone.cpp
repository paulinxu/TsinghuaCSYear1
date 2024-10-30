#include "cone.h"
#include <cmath>

double Cone::area() const
{
    
    double slant = sqrt(h*h + r2*r2);
    return (PI*r2*r2) + (PI*r2*slant);
}

double Cone::volume() const
{
    return PI*r2*r2*h /3;
}