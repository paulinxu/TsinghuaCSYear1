#pragma once
#include <iostream>
using namespace std;

struct Counter
{
public:
    int s, w;
    Counter(int _s = 0, int _w = 0) : s(_s), w(_w) {}
};

template <class T>
class MyWeakPtr;

template <class T>
class MySharedPtr
{
private:
    T *data;
    Counter *refCount;
    void release()
    {
        cout << "data released." << endl;
        delete data;
        delete refCount;
    }

public:
    MySharedPtr()
    {
        cout << "my_sptr constructed." << endl;
        data = nullptr;
        refCount = nullptr;
    }
    MySharedPtr(T *p)
    {
        cout << "my_sptr constructed." << endl;
        data = p;
        refCount = new Counter();
        if (refCount == nullptr)
            return;
        refCount->s++;
    
    }
    MySharedPtr(MySharedPtr<T> &&sp)
    {
        cout << "my_sptr constructed." << endl;
        data = sp.data;
        refCount = sp.refCount;
        sp.data = nullptr;
        sp.refCount = nullptr;
    }
    MySharedPtr(const MyWeakPtr<T> &wp) // PART 3
    {
        cout << "my_sptr constructed." << endl;
        data = wp.data;
        refCount = wp.refCount;
        if (refCount == nullptr)
            return;
        refCount->s++;
    }
    MySharedPtr(const MySharedPtr<T> &sp)
    {
        cout << "my_sptr constructed." << endl;
        data = sp.data;
        refCount = sp.refCount;
        if (refCount == nullptr)
            return;
        refCount->s++;
    }
    ~MySharedPtr()
    {
        cout << "my_sptr destructed." << endl;
        if (*this)
        {
            refCount->s--;
            if (refCount->s == 0)
            {
                release();
            }
        }
    }
    MySharedPtr<T> &operator=(MySharedPtr<T> &&sp)
    {
        cout << "my_sptr updated." << endl;
        if (*this)
        {
            refCount->s--;
            if (this->refCount->s == 0)
            {
                release();
            }
        }
        this->data = sp.data;
        this->refCount = sp.refCount;
        sp.data = nullptr;
        sp.refCount = nullptr;
        return *this;
    }

    operator bool() { return data != nullptr; }

    MySharedPtr<T> &operator=(const MySharedPtr<T> &sp)
    {
        cout << "my_sptr updated." << endl;
        if (*this)
        {
            refCount->s--;
            if (this->refCount->s == 0)
            {
                release();
            }
        }
        this->data = sp.data;
        this->refCount = sp.refCount;
        if (refCount == nullptr)
            return *this;
        refCount->s++;
        return *this;
    }

    int use_count()
    {
        if (*this)
        {
            return refCount->s;
        }
        return 0;
    }
    T &operator*()
    {
        return *data;
    }
    T *operator->()
    {
        return data;
    }

    friend class MyWeakPtr<T>;
};

template <class T>
class MyWeakPtr
{
private:
    Counter *refCount;
    T *data;
    void release()
    {
    }
    operator bool() { return data != nullptr; }

public:
    MyWeakPtr()
    {
        cout << "my_wptr constructed." << endl;
        data = nullptr;
        refCount = nullptr;
    }
    MyWeakPtr(MySharedPtr<T> &sp)
    {
        cout << "my_wptr constructed." << endl;
        data = sp.data;
        refCount = sp.refCount;
        if (refCount == nullptr)
            return;
        refCount->w++;
    }
    MyWeakPtr(const MyWeakPtr &wp)
    {
        cout << "my_wptr constructed." << endl;
        data = wp.data;
        refCount = wp.refCount;
        if (refCount == nullptr)
            return;
        refCount->w++;
    }
    MyWeakPtr(MyWeakPtr &&wp)
    {
        cout << "my_wptr constructed." << endl;
        data = wp.data;
        refCount = wp.refCount;
        wp.data = nullptr;
        wp.refCount = nullptr;
    }
    ~MyWeakPtr()
    {
        cout << "my_wptr destructed." << endl;
        if (refCount == nullptr)
            return;
        refCount->w--;
    }

    MyWeakPtr<T> &operator=(const MyWeakPtr<T> &wp)
    {
        cout << "my_wptr updated." << endl;
        if (*this)
        {
            refCount->w--;
            // if (this->refCount->w == 0)
            // {
            //     release();
            // }
        }
        this->data = wp.data;
        this->refCount = wp.refCount;
        if (refCount == nullptr)
            return *this;
        refCount->w++;
        return *this;
    }

    MyWeakPtr<T> &operator=(const MySharedPtr<T> &sp)
    {
        cout << "my_wptr updated." << endl;
        if (*this)
        {
            refCount->w--;
            // if (this->refCount->w == 0)
            // {
            //     release();
            // }
        }
        this->data = sp.data;
        this->refCount = sp.refCount;
        if (refCount == nullptr)
            return *this;
        refCount->w++;
        return *this;
    }

    MyWeakPtr<T> &operator=(MyWeakPtr<T> &&wp)
    {
        cout << "my_wptr updated." << endl;
        if (*this)
        {
            refCount->w--;
            // if (this->refCount->w == 0)
            // {
            //     release();
            // }
        }
        this->data = wp.data;
        this->refCount = wp.refCount;
        wp.data = nullptr;
        wp.refCount = nullptr;
        return *this;
    }

    bool expired() { return true; }

    MySharedPtr<T> lock()
    {
        if (*this)
        {
            return MySharedPtr<T>(*this);
        }
        else
        {
            return MySharedPtr<T>();
        }
    }

    int use_count()
    {
        if (*this)
        {
            return refCount->s;
        }
        return 0;
    }

    friend class MySharedPtr<T>;
};
