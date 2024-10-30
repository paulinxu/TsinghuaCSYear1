#include "shape.h"

class Polygon : public Shape2D
{
    public:
    
    double n, s;
    Polygon(double n, double s) : n(n) , s(s) {};
    
    double perimeter() const;
    double area() const;  
};