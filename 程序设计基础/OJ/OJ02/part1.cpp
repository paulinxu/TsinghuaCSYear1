#include <iostream>
using namespace std;
 
int main(){
 
    int a;
    int b;
 
    cin >> a >> b; 
 
    a = a/10; //since a is an integer, a takes the floor when divided by 10
    
    // middle value moves to the unit digit
    // modulo 10 operation compares the new unit digit (original middle value)
    
    if (a%10==b){  
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
 
}