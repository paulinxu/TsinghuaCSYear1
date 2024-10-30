#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    getline(cin, text);

    regex get_username("\"username\"[ ]{0,100}:[ ]{0,100}\"([A-Za-z][\\w]{3,14})\"");
    regex get_password("\"password\"[ ]{0,100}:[ ]{0,100}\"([A-Za-z0-9]{8,20})\"");
    regex get_email(R"([\w]+@[\w.]+)");

    smatch sm;

    bool found_username = false;
    bool found_password = false;
    bool found_email = false;

    vector<string> info;

    if (std::regex_search(text, sm, get_username))
    {
        info.push_back(sm[1]);
        found_username = true;
    }
    if (std::regex_search(text, sm, get_password))
    {
        string password = sm[1];

        regex containsint("[0-9]");
        regex containschar("[a-zA-Z]");
        if (regex_search(password, sm, containsint) && regex_search(password, sm, containschar))
        {
            found_password = true;
            info.push_back(password);
        }
    }
    if (std::regex_search(text, sm, get_email))
    {
        string email = sm[0];
        // regex cleancoma(",");
        // email = regex_replace(email, cleancoma, "");
        info.push_back(email);
        found_email = true;
    }

    if (found_username && found_password && found_email)
    {

        for (int i = 3; i < info[0].length(); i++)
        {
            info[0][i] = '*';
        }
        for (int i = 0; i < info[1].length(); i++)
        {
            info[1][i] = '*';
        }
        for (int i = 0; i < info[2].length(); i++)
        {
            if (info[2][i] != '@' && info[2][i] != '.')
            {
                info[2][i] = '*';
            }
        }

        cout << "Successfully registered." << endl;
        cout << "username: " << info[0] << endl;
        cout << "password: " << info[1] << endl;
        cout << "email: " << info[2] << endl;
    }
    else
    {
        cout << "Illegal ";
        if (!found_username)
        {
            cout << "username";
            if (found_password + found_email < 2)
            {
                cout << ',';
            }
        }
        if (!found_password)
        {
            cout << "password";
            if (found_email == 0)
            {
                cout << ',';
            }
        }
        if (!found_email)
        {
            cout << "email";
        }
    }
}