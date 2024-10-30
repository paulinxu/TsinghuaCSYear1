#include "shape.h"

class Circle : public Shape2D
{
    public:
    
    double r;
    Circle(double r1) : r(r1) {};
    
    double perimeter() const;
    double area() const;  
};