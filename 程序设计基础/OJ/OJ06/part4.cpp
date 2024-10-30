#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isA(char n){if ((int(n)>=65 && int(n)<=90)||(int(n)>=97 && int(n)<=122)){return true;}
else{return false;}}

int main(){
    string text;
    getline(cin, text);
    int start = 0;
    int end = 0;
    for (int i = 0; i<text.length();i++){
        if(!isA(text[i])){
            end=i;
            for(int x=end-1; x>=start; x--){
                cout << text[x];
            }
            cout << text[i];
            start=end+1;
        }
        else if (i==text.length()-1){
            for(int x=text.length()-1; x>=start; x--){
                cout << text[x];
            }
        }

    }
}