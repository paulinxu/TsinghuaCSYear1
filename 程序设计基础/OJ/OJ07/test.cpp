#include <iostream>
using namespace std;

string getlargest(string a, string b){

    if (a.length()<b.length()){
        for (int i = 0; i<a.length(); i++){
            if (int(a[i])<int(b[i])){
                return a;
            }
            else if (int(a[i])>int(b[i])){
                return b;
            }
        }
        return a;
    }
    else {
        for (int i = 0; i<b.length(); i++){
            if (int(b[i])<int(a[i])){
                return b;
            }
            else if (int(b[i])>int(a[i])){
                return a;
            }
        }
        return b;
    }
}

int main(){

    cout << getlargest("abc", "ab");

}