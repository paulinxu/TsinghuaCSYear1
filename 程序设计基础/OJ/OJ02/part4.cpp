#include <iostream>
using namespace std;
 
int main(){
    int a;
    cin >> a;
    //checks if the year is the first of a century, which abides by different rules
    if (a%100==0){
        if (a%400==0){
            cout << "YES";
        }
        else{
            cout <<"NO";
        }
    }
    // if the year is NOT the first of a century, then it follows normal rules where a leap year is divisible by 4
    else{
        if(a%4==0){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
}