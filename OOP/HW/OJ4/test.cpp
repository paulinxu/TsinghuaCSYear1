#include <iostream>
using namespace std;

// (1)
template <typename T0>
class A
{
    T0 value;

public:
    void set(const T0 &v)
    {
        value = v;
    }
    T0 get();
};

// (2)
template <typename T1>
T1 A<T1>::get() { return value; }

template <typename T0, typename T1>
T1 sum(T0 a, T0 b)
{
    return T1(a.get() + b.get());
}

int main()
{
    A<double> a;
    a.set(4.3);
    cout << a.get() << endl;
    cout << sum<A<double>, int>(a, a) << endl;
    // (3)
    return 0;
}