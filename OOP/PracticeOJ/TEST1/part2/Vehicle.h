#pragma once
#include <iostream>

using namespace std;

class Vehicle
{
    public:
    int max_wheels;
    int max_wings;
    int wheels = 0;
    int wings = 0;

    void set_max_wheel_num(int i){max_wheels = i;}
    void set_max_wing_num(int i){max_wings = i;}
    void add_wheel()
    {
        wheels++;
    }
    void add_wing()
    {
        wings++;
    }
    bool finished()
    {
        return (wheels >= max_wheels) && (wings >= max_wings);
    }
    void run()
    {
        cout << "I am running" << endl;
    }

};