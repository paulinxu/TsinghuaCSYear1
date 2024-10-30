#pragma once

class Animal
{
    public: 
    int color;
    virtual void sing() = 0;
    virtual void swim() = 0;
    virtual ~Animal(){};
};