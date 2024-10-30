#include <iostream>
using namespace std;
bool checkSpecial(int i, int n);      // 未定义，需要完成
 
int main() {
    int n;
    cin >> n;
    for (int i = 10000; i < 1000000; i ++) {
        if (checkSpecial(i, n)) {
            cout << i << endl;
        }
    }
    return 0;
}
bool checkSpecial(int i, int n)
{
    if (i >= 100000)
    {
        int p1 = i / 100000;
        int p2 = (i % 100000) / 10000;
        int p3 = (i % 10000) / 1000;
        int p4 = (i % 1000) / 100;
        int p5 = (i % 100) / 10;
        int p6 = i % 10;
 
        if ((p1 == p6) && (p2 == p5) && (p3 == p4) && p1 + p2 + p3 + p4 + p5 + p6 == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int p1 = (i % 100000) / 10000;
        int p2 = (i % 10000) / 1000;
        int p3 = (i % 1000) / 100;
        int p4 = (i % 100) / 10;
        int p5 = i % 10;
        if ((p1 == p5) && (p2 == p4) && p1 + p2 + p3 + p4 + p5 == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}