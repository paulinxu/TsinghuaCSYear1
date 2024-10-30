#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main()
{
    float a;
    float b;
    float c;
    cin >> a >> b >> c;
    float p = (a + b + c) / 2;
    float s = sqrt(p * (p - a) * (p - b) * (p - c));
 
    cout << fixed << setprecision(2) << s << endl;
}