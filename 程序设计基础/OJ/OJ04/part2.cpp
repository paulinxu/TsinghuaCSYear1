#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    cin >> a >> b;
    for (int i = 0; i < b; i++){
        cout << "*";
    }
    cout << endl;
    for (int row = 0; row < a-2 ; row++){
        cout << "*";
        for (int space = 0; space < b-2; space++){
            cout << " ";
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < b; i++){
        cout << "*";
    }
}