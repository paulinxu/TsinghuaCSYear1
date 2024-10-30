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
    string c;
    getline(fin, c);

    string result = "";

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
                
                for(int p=0; p<i ;p++){
                    result += a[p];
                }
                result += c;
                for (int p=i+b.length(); p<a.length(); p++){
                    result += a[p];
                }

                fout << result;
                found = true;
                break;
            }
        }
    }
    if (!found){
        fout << a;
    }
}