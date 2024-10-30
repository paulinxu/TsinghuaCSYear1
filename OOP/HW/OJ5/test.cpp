#include <iostream>
#include <vector>


using namespace std;

template<typename T, typename W> 
T add(T a, W b)
{
    return a+b;
}
template<typename T> 
T sub(T a, T b)
{
    return a-b;
}

int main()
{
    cout << add<int, double>(1.3, 4.5) << endl;
}
