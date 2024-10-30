#include <string>

using namespace std;

template <class RealShape>
class Shape {
protected:
    int a, b;
    static int createCount;
    static int aliveCount;
public:
    std::string type() 
    {
        return static_cast<RealShape*>(this)->typeImpl();
    }
    int area() 
    {
        return static_cast<RealShape*>(this)->areaImpl();
    }
    Shape* print()
    {
        std::cout << "Area of " << type() << ": " << area() << std::endl;
        return this;
    }
    Shape* zoom(int k)
    {
        a*=k;
        b*=k;
        return this;
    }
    static int getCreate()
    {
        return createCount;
    };
    static int getAlive()
    {
        return aliveCount;
    };
    Shape(int a, int b): a(a) , b(b) 
    {
        createCount++;
        aliveCount++;
    }
    ~Shape()
    {
        aliveCount--;
    }
};
template <class RealShape>
int Shape<RealShape>::createCount = 0;
template <class RealShape>
int Shape<RealShape>::aliveCount = 0;

class Triangle : public Shape<Triangle>
{
public:
    using Shape::Shape;
    std::string typeImpl() {return "Triangle";};
    int areaImpl() {return a*b/2;};
};

class Rectangle : public Shape<Rectangle>
{
public:
    using Shape::Shape;
    std::string typeImpl() {return "Rectangle";};
    int areaImpl() {return a*b;};
};