#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin1("testresults2.txt");
    ifstream fin2("testresultsnew.txt"); // 填入你的输出文件
    string a, b;
    int counter = 1;
    bool flag = true;
    while (getline(fin1, a) && getline(fin2, b))
    {
        if (!a.empty() && a[a.size() - 1] == '\r')
        {
            a.erase(a.size() - 1);
        }
        if (!b.empty() && b[b.size() - 1] == '\r')
        {
            b.erase(b.size() - 1);
        }
        if (a != b)
        {
            cout << "Error on line " << counter << endl;
            flag = false;
        }
        counter++;
    }
    if (flag == 1)
        cout << "IDENTICAL!" << endl;
    fin1.close();
    fin2.close();
    return 0;
}