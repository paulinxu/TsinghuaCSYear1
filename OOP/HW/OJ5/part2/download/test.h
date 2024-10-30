#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
};

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
    
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
    }

    A* find(Pos p) {
        for(auto t = base.begin(); t != base.end(); ++t) {
            if(p == t->pos) return &(t->value);
        }
        return NULL;
    }
};

#endif
