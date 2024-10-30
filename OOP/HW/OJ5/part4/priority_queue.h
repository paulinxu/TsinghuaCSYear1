#pragma once
#include "abstract_compare.h"
#include <vector>

template<class T> class PriorityQueue {
public:

    AbstractCompare<T> *cmp;
    std::vector<T> q;

    PriorityQueue(AbstractCompare<T> *_cmp) : cmp(_cmp) {}

    ~PriorityQueue() {}

    bool empty()
    {
        if (q.size() == 0) {return true;}
        return false;
    }

    int size()
    {
        return q.size();
    }

    void push(T element)
    {
        auto it = q.begin();
        for (; it != q.end(); ++it)
        {
            if (cmp->compare(element, *it))
            {
                break;
            }
        }
        q.insert(it, element);
    }

    void pop()
    {
        q.erase(q.begin());
    }

    T top()
    {
        return *q.begin();
    }
};
