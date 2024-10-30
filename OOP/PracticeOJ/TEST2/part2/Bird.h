#pragma once

using namespace std;
class Bird : public Animal
{
    int color;
    public:
    Bird(int color) : color(color){};
    void sing() 
    {
        if (color == 0) 
        {
            cout << "Red bird is singing." << endl;
        }
        else{
            cout << "Blue bird is singing." << endl;
        }
    }
    void swim() 
    {
        cout << "Bird can not swim." << endl;
    }
    virtual ~Bird()
    {
        if (color == 0) 
        {
            cout << "Red bird is gone." << endl;
        }
        else{
            cout << "Blue bird is gone." << endl;
        }
    }
};