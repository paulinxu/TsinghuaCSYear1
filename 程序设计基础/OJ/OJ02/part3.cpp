#include <iostream>
#include <iomanip>
using namespace std;
 
int main(){
    float sum = 0;
    float count = 0;
    int num;
 
    for (int i = 0; i<=5; i=i+1){
        cin >> num; 
        // for each new input integer, if it satisfies the conditions, then it is added to the total sum
        // whenever an integer is satisfactory, the number count is incremented by 1 to find the average later
        if ((num%2==1) && (num%3==0)){
            sum += num;
            count += 1;
        }
    }
 
    //if else statement avoid division by 0, which would give an error
    if (count > 0){
        cout << fixed << setprecision(4) << sum/count;
    }
    else{
        cout << fixed << setprecision(4) << 0.0000;
    } 
    return 0;
}