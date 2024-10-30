#pragma once

class Shape
{
    public:
    double area;
    double getArea()
    {
        return area;
    }
};

class Rectangle : public Shape
{
    public:
    double w, h;
    Rectangle(double width, double height);

};

class Circle : public Shape
{
    public:
    double r;
    Circle(double radius);
};