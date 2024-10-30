#include <iostream>
using namespace std;

int main(){
    char people[4] = {'A','B','C','D'};
    char person;
    int sum = 0;

    for (int i = 0; i<=3 ; i++){
        person = people[i];

        if (person != 'A') sum++;
        if (person == 'B') sum++;
        if (person != 'B') sum++;
        if (person == 'C') sum++;

        if (sum == 3) cout << person;

        sum = 0;
    }


}