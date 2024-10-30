#include <iostream>
using namespace std;

int main(){
    char person = 'A';
    int sum;
    for (int i = 0; i<=3 ; i++){
        person = 'A'+i;
        sum = (person != 'A') + (person == 'B') + (person != 'B') + (person == 'C');
        if (sum == 3) cout << person;
    }
}