#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    string a;
    getline(fin, a);
    string b;
    getline(fin, b);

    bool found = false;
    for (int i = 0; i < a.length(); i++){
        if (a[i] == b[0]){
            bool match = true;
            for (int x = 0; x<b.length() ; x++){
                if (a[i+x]!=b[x]){
                    match = false;
                    break;
                }
            }
            if (match){
                fout << i;
                found = true;
                break;
            }
        }
    }
    if (!found){
        fout << -1;
    }
}