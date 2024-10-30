#pragma once
#include <memory>
#include <list>
#include <vector>
#include "event.h"

using namespace std;

class Window;

int current_time = 0;

class Widget {
    string _name;
    Window* _parent;

public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};

class Checkbox :public Widget, public Click {
    // TODO
    public:
    vector<bool> timeline; // assumes all checkboxes created before actions

    Checkbox(string name) :Widget(name) , timeline(vector<bool>(0)){}
    bool selected = false;
    void click();
};

class Window {

private:
    list<shared_ptr<Widget>> Widgets; 

public:
    // TODO
    list<shared_ptr<Checkbox>> Checkboxes;
    shared_ptr<Widget> getPointerByName(string name)
    {
        for (auto& x : Widgets)
        {
            if (x -> getName() == name)
            {
                return x;
            }
        }
        return nullptr;
    }
    // TODO
    Widget& getElementByName(string name)
    {
        for (auto& x : Widgets)
        {
            if (x -> getName() == name)
            {
                return *x;
            }
        }
    }
    // TODO
    bool addElement(shared_ptr<Widget> w)
    {
        {
        for (auto& x : Widgets)
        {
            if (x -> getName() == w -> getName())
            {
                return false;
            }
        }
        
        Widgets.push_back(w);

        if (dynamic_pointer_cast<Checkbox>(w))
        {
            w->setParent(this);
            Checkboxes.push_back(dynamic_pointer_cast<Checkbox>(w));
        }

        return true;
        }
    }
    // TODO
    bool undo()
    {
        if(current_time -1 < 0)
        {
            return false;
        }

        current_time--;
        for (auto& x : Checkboxes)
        {
            //debug
            // cout << "TIMELINE " << x -> getName() <<':';
            // for (int i = 0 ; i < x -> timeline.size() ; i ++)
            // {
            //     cout << x -> timeline[i] << ','; 
            // }
            // cout << endl;
            //end

            x -> selected = x -> timeline[current_time];
            x -> timeline.pop_back();
        }
        return true;
    }
};

void Checkbox::click() 
{
    
    current_time++;
    if (!getParent())
    {
        // cout << "Parent not found " << endl;
        return;
    }
    for (auto& x : getParent() -> Checkboxes)
    {
        x -> timeline.push_back(selected);
        // cout << "LOG: " << x -> getName() << " pushedback " << selected << endl;
    }

    selected = !selected;
}