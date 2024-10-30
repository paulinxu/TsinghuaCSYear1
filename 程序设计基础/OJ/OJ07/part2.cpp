#include <iostream>
#include <string>
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
    if ((int(a) >= 97 && int(a) <= 122) || (int(a) >= 48 && int(a) <= 57))
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
    string text = "A man, a plan, a canal: Panama";
 
    getline(cin, text);
 
    text = toLower(text);
 
    string text2 = "";
 
    for (int i = 0; i < text.length(); i++)
    {
        if (isValid(text[i]))
        {
            text2 += text[i];
        }
    }
 
    bool flag = true;
    for (int i = 0; i < int(text2.length() / 2); i++)
    {
        if (text2[i] != text2[text2.length() - 1 - i])
        {
            flag = false;
        }
    }
 
    if (flag)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}