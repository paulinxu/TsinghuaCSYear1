#include <iostream>
using namespace std;
 
int main()
{
    int base2;
    cin >> base2;
 
    int sum = 0;
    int b10 = 1;
    int b2 = 1;
    for (int i = 0; i < 4; i++)
    {
        if ((base2 % (b10 * 10)) / b10 == 1)
        {
            sum += b2;
        }
        b10 = b10 * 10;
        b2 = b2 * 2;
    }
 
    cout << sum << endl;
}