#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    int m;
    fin >> n >> m;

    string name;
    float sum = 0;
    bool first = true;

    for (int i = 0; i<n ; i++){
        fin >> name;
        float score;
        for (int x = 0 ; x < 4 ; x++){
            fin >> score;
            sum += score;
        }
        if (sum < m){
            if (first){
                fout << name;
                first = false;
            }
            else{
                fout << endl << name;
            }
        }
        sum = 0;
    }
}