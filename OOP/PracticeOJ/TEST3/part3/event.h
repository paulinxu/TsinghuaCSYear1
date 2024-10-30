#pragma once
#include <functional>
using namespace std;



class Click {
private:
    function<void()> func;
public:
    // TODO
    Click(){}
    // TODO
    void setClickCommand(std::function<void()> f)
    {
        // cout << "CALLED Click::setClickCommand" << endl;
        func = f;
    }
    // TODO
    virtual void click()
    {
        // cout << "CALLED Click::click" << endl;
        if (func)
        {
            func();
        }
    }
};
class DoubleClick {
private:
    // TODO
    function<void()> func;
public:
    // TODO
    DoubleClick(){}
    // TODO
    void setDoubleClickCommand(std::function<void()> f)
    {
        func = f;
    }
    // TODO
    virtual void doubleClick()
    {
        if (func)
        {
            func();
        }
    }
};