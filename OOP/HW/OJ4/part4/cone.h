#include "shape.h"

class Cone : public Shape3D
{
    public:
    
    double r2, h;

    Cone(double r2, double h) : r2(r2) , h(h) {};
    
    double area() const;
    double volume() const;
    
};