#include <iostream>
using namespace std;

int x;

int f(int n){
    if (n == 1){
        return x;
    }
    else if (n <= 0){
        return 0;
    }
    else{
        return f(n-1) + f(n/2) + f(n/3);
    }
}

int main(){
    int n;
    cin >> x >> n;
    cout << f(n);
}