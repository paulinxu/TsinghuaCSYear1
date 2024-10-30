#include <iostream>
using namespace std;

int main(){

    string elements;
    cin >> elements;
    
    for (int i=0; i<elements.length();i++){
        if (i%2==0){ // refers to odd cases since index is shifted by 1
            if (int(elements[i])>=97 && int(elements[i])<=122){
                cout << char(int(elements[i])-32);
            }
            else{
                cout << elements[i];
            }
        }
        else {
            if (int(elements[i])>=48 && int(elements[i])<=57){
                if (int(elements[i])==57){
                    cout << char(48);
                }
                else{
                    cout << char(int(elements[i])+1);
                }
            }
            else{
                cout << elements[i];
            }
        }
    }
}