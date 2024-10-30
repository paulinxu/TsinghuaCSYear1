#include <iostream>
using namespace std;
 
int main()
{
    int n;
    int x;
    cin >> n;
    int a[n];
    int b[n];
 
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
    }
 
    for (int i = 0; i < n; i++)
    { 
        // insert
        cout << "Insert element[" << i+1 << "]:" << endl;
        b[i] = a[i];
        x = a[i];
        // init
        cout << "  Init:";
        for (int ii = 0; ii <= i; ii++)
        {
            cout << b[ii];
            if (ii != i)
            {
                cout << " ";
            }
        }
        cout << endl;
        // move
        if (i != 0)
        {
            int pos = i;
            while (true)
            {
                int check = b[pos - 1];
                if (check > x && pos != 0)
                {
                    cout << "  Move back:";
                    b[pos] = check;
                    for (int ii = 0; ii <= i; ii++)
                    {
                        cout << b[ii];
                        if (ii != i)
                        {
                            cout << " ";
                        }
                    }
                    cout << endl;
                    pos--;
                }
                else
                {
                    b[pos] = x;
                    break;
                }
            }
        }
 
        // final
        cout << "  Final:";
        for (int ii = 0; ii <= i; ii++)
        {
            cout << b[ii];
            if (ii != i)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}