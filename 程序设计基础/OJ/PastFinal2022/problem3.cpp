#include <iostream>
#include <vector>

using namespace std;

int main(){

    char people[4] = {};

    cin >> people[0] >> people[1] >> people[2] >> people[3];

    vector<char> solutions;

    char chars[4] = {'A', 'B','C', 'D'};
    
    for (int i = 0 ; i < 4 ; i ++) {

        bool a = people[0] == chars[i];
        bool b = !(people[1] == chars[i]);
        bool c = people[2] == chars[i];
        bool d = !(people[3] == chars[i]);

        int sum = a + b + c + d;

        if (sum == 2){
            solutions.push_back(chars[i]);
        } 
    }

    for (int i = 0 ; i < solutions.size() ; i ++){
        char minchar = solutions[i];
        int minpos = i;
        for (int j = i ; j < solutions.size() ; j ++){
            if (solutions[j] < minchar){
                minchar = solutions[j];
                minpos = j;
            }
        }
        solutions[minpos] = solutions[i];
        solutions[i] = minchar;
    }

    for (int i = 0 ; i < solutions.size() ; i ++){
        cout << solutions[i];
    }

}