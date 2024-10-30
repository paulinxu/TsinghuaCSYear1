#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin;
    fin.open("inp");
    ofstream fout;
    fout.open("oup");
    
    vector<string> words(0);

    if (fin && fout){
        string word;
        while (fin >> word){
            words.push_back(word);
        }

    for (int i = words.size()-1; i>=0 ; i--){
        if (i == words.size()-1){
            fout << words[i];
        }
        else{
            fout << ' ' << words[i];
        }
    }    
    fout.close();
    fin.close();
    }
}