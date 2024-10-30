#include <iostream>
#include <string>
#include <iomanip>
 
using namespace std;
 
string toLower(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (int(a[i]) >= 65 && int(a[i]) <= 90)
        {
            a[i] = a[i] + 32;
        }
    }
    return a;
}
 
bool isValid(char a)
{
    if ((int(a) >= 97 && int(a) <= 122))
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
int main()
{
    string text;
    getline(cin, text);
    text = toLower(text);
 
    int counter[26] = {0};
 
    for (int i = 0; i < text.length(); i++)
    {
        if (isValid(text[i]))
        {
            counter[int(text[i]) - 97]++;
        }
    }
 
    float total = 0;
    for (int i = 0; i < 26; i++)
    {
        total += counter[i];
    }
 
    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 97);
        cout << " ";
        cout << fixed << setprecision(2) << counter[i] / total * 100;
        cout << "%";
        cout << endl;
    }
}