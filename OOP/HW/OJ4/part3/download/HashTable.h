#pragma once

#include <string>
#include <iostream>

#include "Hash.h"

using namespace std;

template <typename T1, typename T2>
class HashTable
{
public:

    T2 arr[5000];
    bool isEmpty[5000];
    int n;

    HashTable(int n) : n(n) 
    {
        // cout << "created table of length " << n << endl;
        for (int i = 0 ; i < 5000 ; i ++)
        {
            isEmpty[i] = true;
        }
    };
    // ~HashTable()
    // {
    //     delete [] arr;
    //     delete [] isEmpty;
    // }

    void addItem(const T1 &key, const T2 &value)
    {
        Hash<T1> hash(n);
        int pos = hash(key);
        // cout << pos << endl;
        arr[pos] = value;
        isEmpty[pos] = false;
        // cout << pos << ' ' << value << " added" << endl;
    }

    void removeItem(const T1 &key)
    {
        Hash<T1> hash(n);
        int pos = hash(key);
        isEmpty[pos] = true;
    }

    T2 *findByKey(const T1 &key)
    {
        Hash<T1> hash(n);
        int pos = hash(key);
        if (isEmpty[pos] == true)
        {
            return nullptr;
        }
        return &arr[pos];
    }
};