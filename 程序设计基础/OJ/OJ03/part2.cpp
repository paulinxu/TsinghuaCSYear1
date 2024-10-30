#include <iostream>
using namespace std;

int main(){
    char people[6] = {'A','B','C','D','E','F'};     
    char person;
    int sum = 0;

    for (int i = 0; i<=5 ; i++){
        person = people[i];

        bool a = (person != 'A');
        bool b = (person == 'A' || person == 'C');
        bool c = (!a && !b);
        bool f = (person == 'F');
        bool d = (!c && !f);
        bool e = (a && d && !b && !c && !f);

        if (a) sum++;
        if (b) sum++;
        if (c) sum++;
        if (d) sum++;
        if (e) sum++;
        if (f) sum++;

        if (sum==3){
            cout << person << endl;
        }

        sum = 0;
    }
}