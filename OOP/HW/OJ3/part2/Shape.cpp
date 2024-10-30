#include "Shape.h"

Rectangle::Rectangle(double width, double height) : w(width), h(height){area = w*h;};

Circle::Circle(double radius) : r(radius) {area = 3.14 * r * r;};

 