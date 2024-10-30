#include "shape.h"

class Cylinder : public Shape3D
{
    public:
    double r2, h;
    Cylinder(double r2, double h) : r2(r2) , h(h) {};

    double area() const;
    double volume() const;
};