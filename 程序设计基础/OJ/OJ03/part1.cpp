#include <iostream>
using namespace std;

int main(){
    char people[4] = {'A','B','C','D'};
    char person;
    int sum = 0;

    for (int i = 0; i<=3; i++){
        person = people[i];

        if (person != 'A') sum++;
        if (person == 'D') sum++;
        if (person == 'B') sum++;
        if (person != 'D') sum++;
        
        if (sum==1) cout << person;

        sum = 0;
    }
}