#include <iostream>
using namespace std;

struct student{
    string name;
    int average;
    int evaluation;
    char leader;
    char west;
    int papers;
    int scholarship =0;
};

int main(){
    int n, total = 0;
    cin >> n;

    student *list;
    list = new student[n];

    for (int i = 0; i < n ; i++){
        cin >> list[i].name >> list[i].average >> list[i].evaluation >> list[i].leader >> list[i].west >> list[i].papers;
        //cout << list[i].name << list[i].average << list[i].evaluation << list[i].leader << list[i].west << list[i].papers << endl; 
    }
    for (int i = 0; i < n ; i++){
        if (list[i].average > 80 && list[i].papers >= 1){
            list[i].scholarship += 8000;
            total += 8000;
        }
        if (list[i].average > 85 && list[i].evaluation > 80){
            list[i].scholarship += 4000;
            total += 4000;
        }
        if (list[i].average > 90){
            list[i].scholarship += 2000;
            total += 2000;
        }
        if (list[i].average > 85 && list[i].west == 'Y'){
            list[i].scholarship += 1000;
            total += 1000;
        }
        if (list[i].evaluation > 80 && list[i].leader == 'Y'){
            list[i].scholarship += 850;
            total += 850;
        }
    }
    int maxpos = 0;
    int max = 0;
    for (int i = 0; i<n ; i++){
        
        if (list[i].scholarship > max){
            max = list[i].scholarship;
            maxpos = i;
        }
    }

    cout << list[maxpos].name << endl;
    cout << list[maxpos].scholarship << endl;
    cout << total << endl;


}