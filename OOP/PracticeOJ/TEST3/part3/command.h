#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

class ClearAll {
    // TODO
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO 
    ClearAll(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox) {}
    void operator()()
    {
        
        current_time++;
        
        auto& first = checkbox.front();
        for (auto& x : first -> getParent() -> Checkboxes)
        {
            x -> timeline.push_back(x -> selected);
            // cout << "LOG: " << x -> getName() << " pushedback " << x -> selected << endl;
        }
        
        
        for (auto& x : checkbox)
        {
            x -> selected = false;
        }
    }
};

class SelectAll {
    // ...
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox){}
    void operator()()
    {
        
        current_time++;
        auto& first = checkbox.front();
        for (auto& x : first -> getParent() -> Checkboxes)
        {
            x -> timeline.push_back(x -> selected);
            // cout << "LOG: " << x -> getName() << " pushedback " << x -> selected << endl;
        }
        
        for (auto& x : checkbox)
        {
            x -> selected = true;
        }
    }
};

class Submit {
    // ...
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox){}
    void operator()()
    {
        for (auto& x : checkbox)
        {
            if (x -> selected == true)
            {
                cout << x -> getName() << " is selected\n";
            }
            else
            {
                cout << x -> getName() << " is not selected\n";
            }
        }
    }
};