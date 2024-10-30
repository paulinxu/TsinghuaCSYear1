#pragma once

using namespace std;
class Fish : public Animal
{
    int color;
    public:
    Fish(int color) : color(color){};
    void swim() 
    {
        if (color == 0) 
        {
            cout << "Red fish is swimming." << endl;
        }
        else{
            cout << "Blue fish is swimming." << endl;
        }
    }
    void sing() 
    {
        cout << "Fish can not sing." << endl;
    }
    virtual ~Fish()
    {
        if (color == 0) 
        {
            cout << "Red fish is gone." << endl;
        }
        else{
            cout << "Blue fish is gone." << endl;
        }
    }
};