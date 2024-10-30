#include "compare.h"
#include <string>

class type1 : public AbstractCompare<int>
{
    bool compare(int a, int b)
    {
        return a < b;
    }
};
class type2 : public AbstractCompare<int>
{
    bool compare(int a, int b)
    {
        std::string str_a = std::to_string(a);
        std::string str_b = std::to_string(b);
        int sum_a = 0;
        int sum_b = 0;
        for (char x : str_a)
        {
            sum_a += (x - '0');
        }
        for (char x : str_b)
        {
            sum_b += (x - '0');
        }
        if (sum_a < sum_b) 
        {
            return true;
        }
        else if(sum_a > sum_b)
        {
            return false;
        }
        return a < b;
    }
};
class type3 : public AbstractCompare<Point>
{
    bool compare(Point a, Point b)
    {
        if (a.x != b.x)
        {
            return a.x < b.x;
        }
        return a.y < b.y; 
    }
};
class type4 : public AbstractCompare<Point>
{
    bool compare(Point a, Point b)
    {
        int dist_a = a.x*a.x + a.y*a.y;
        int dist_b = b.x*b.x + b.y*b.y;

        if (dist_a != dist_b)
        {
            return dist_a < dist_b;
        }

        if (a.x != b.x)
        {
            return a.x < b.x;
        }
        return a.y < b.y; 
    }
};


AbstractCompare<int>* get_compare_int(int type)
{
    if (type == 1)
    {
        return new type1;
    }
    else 
    {
        return new type2;
    }
}

AbstractCompare<Point>* get_compare_point(int type)
{
    if (type == 3)
    {
        return new type3;
    }
    else 
    {
        return new type4;
    }
}