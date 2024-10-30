#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    for (int i = 2; i<= sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int count;
    cin >> count;

    int n;
    for (int c = 0; c < count; c++){
        cin >> n;
        cout << n << "=";
        
        int d = 2;
        while (n>1){
            if (isPrime(d) && n%d==0){
                n=n/d;
                cout << d;
                if (n!=1){
                    cout << "*";
                }
            }
            else{
                d++;
            }
        }


        cout << endl;
    }

}