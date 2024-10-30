#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
    Point (Pos p): pos(p) {}
};

template<class A>
bool isLesser(Point<A> a, Point<A> b)
{
    if (a.pos.first > b.pos.first) 
    {
        return false;
    }
    else if (a.pos.first < b.pos.first)
    {
        return true;
    }
    if (a.pos.second > b.pos.second)
    {
        return false;
    }
    return true;
}

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;

    bool sorted = false;
    
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));


        // to delete
        // using namespace std;
        // cout << "SORTED: ";
        // for (auto &t : base)
        // {
        //     cout << "(" << t.pos.first << "," << t.pos.second << ")";
        // }
        // cout << endl;
        //// to delete

    }

    A* find(Pos p) {

        if (!sorted)
        {
            sort(base.begin(), base.end(), isLesser<A>);
            // std::cout << "SORT" << std::endl;
            sorted = true;
        }

        // std::vector< Point<A> >::iterator low;
        auto low = std::lower_bound(base.begin(), base.end(), Point<A>(p), isLesser<A>);

        if (low - base.begin() != 0)
        {
            low --;
        }
        // std::cout << low -> pos.first << low -> pos.second << std::endl;

        if(p == low -> pos)
        {
            return &(low -> value);
        }
        
        return NULL;
    }
};


// make for map

template <class A>
class Container<A, map<Pos, A> > : public BasicContainer<A> {
    map< Pos, A > base;
    
public:
    void insert(const Pos &p, const A &v) {
        base.insert(make_pair(p, v));
    }

    A* find(Pos p) {
        
        auto low = base.find(p);

        if (low -> first == p)
        {
            return &(low -> second);
        }

        return NULL;
    }
};

#endif
