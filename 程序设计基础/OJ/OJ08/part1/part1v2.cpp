#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
string reverse(string line){
    string result = "";
    for (int i = line.length()-1; i>=0 ; i--){
        result += line[i];
    }
    return result;
}
 
int main(){
    ifstream fin;
    fin.open("inp");
    ofstream fout;
    fout.open("oup");
    
    vector<string> lines(0);
    string line;
    while (getline(fin, line)){
        lines.push_back(line);
    }
    for (int i = lines.size()-1 ; i>=0; i--){
        fout << reverse(lines[i]) << endl;
    }
    fin.close();
    fout.close();
}