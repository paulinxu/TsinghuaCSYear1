#include <iostream>
using namespace std;

bool isLeap(int a){
    if (a%100 == 0){ 
        if (a%400 ==0){
            return true;
        }
        else{
            return false;
        }
    } 
    else{
        if (a%4 == 0){
            return true;
        }
        else{
            return false;
        }
    }
}

int getDays(int year, int month, int day){
    // base 2021, 1, 1

    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sum = 0;

    for (int i = 2021; i < year ;i ++){
        if (isLeap(i)){
            sum += 366;
        }
        else{
            sum += 365;
        }
    }

    for (int i = 1; i < month ; i ++){
        sum += months[i];
        if (isLeap(year) && i == 2){
            sum++;
        }
    }

    sum += day;

    return sum;

}

int main(){
    
    int data1, data2;
    cin >> data1 >> data2;

    int d1 = data1 %100;
    int d2 = data2 %100;
    data1 /= 100;
    data2 /= 100;

    int m1 = data1 %100;
    int m2 = data2 %100;
    data1 /= 100;
    data2 /= 100;

    int y1 = data1;
    int y2 = data2;

    cout << getDays(y2, m2, d2) - getDays(y1, m1, d1) + 1; 

}   