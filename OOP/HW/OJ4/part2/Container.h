#pragma once
#include <vector>
#include <iostream>

using namespace std;

template<class A>
struct entry
{
    int user_id;
    int post_id;
    A item;
};

template<class A>
class Container
{
    public:
    int pos = 0; 
    
    entry<A> entries[1000];

    void insert(int x, int y, A item)
    {
        entry<A> temp;
        temp.user_id = x;
        temp.post_id = y;
        temp.item = item;
        entries[pos] = temp;
        // cout << x << y << item << " added in pos " << pos << endl; 
        pos ++;
    }

    A* find(int x, int y)
    {
        for (int i = 0 ; i < pos ; i ++)
        {
            // cout << "serching at: " << i << endl;
            if (entries[i].user_id == x && entries[i].post_id == y)
            {
                // cout << x << y << " found in pos " << pos << endl; 
                return &entries[i].item;
            }
        }
        return NULL;
    } 

};