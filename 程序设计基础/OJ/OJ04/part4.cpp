#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int num;
    bool appearnegative = false;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if ((num % 3 == 0 || num % 5 == 0) && (num < 1000) && (!appearnegative) && (count < 10))
        {
            sum += num;
            count++;
        }
        if (num == -1)
            appearnegative = true;
    }
    cout << sum;
}