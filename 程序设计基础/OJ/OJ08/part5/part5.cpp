#include <iostream>
#include <vector>
using namespace std;

bool isLucky(int n){
    while(n>0){
        if (n%10 == 7){
            return true;
        }
        n /= 10;
    }
    return false;
}
int main(){
    int a, b;
    cin >> a >> b;
    vector<bool> nums(b+1);

    for (int i = 0; i<b+1 ; i++){
        nums[i] = false;
    }
    for (int i = 0; i<b+1 ; i++){
        if (isLucky(i)){
            int x = 1;
            while (i*x<=b){
                nums[i*x] = true;
                x++;
            }
        }
    }
    int count = 0;
    for (int i = a; i<b+1 ; i++){
        if (nums[i] == false){
            count ++;
        }
    }
    cout << count;
}