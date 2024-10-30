#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct instruction{

    string name;

    // integer declaration params

    string type;
    string var_name; 
    int value;
    
    // for params

    int variable;
    int max;
    int min;
    int skip;

    // loop params

    int repetitions;

    // if params

    string condition;

    // print params

    string text;

};

vector<instruction> instructions(0);

int n;

void handle_input(){

    ifstream fin("input.txt");
    fin >> n;

    for (int i = 0; i < n ; i ++){
        instruction current;

        fin >> current.name;
    

        if (current.name == "close"){
            
        }

        if (current.name == "loop"){
            
            fin >> current.repetitions;
        }

        if (current.name == "print"){
            fin >> current.text;
        }
        
        instructions.push_back(current);
    }

}

void handle_output(){

    ofstream fout("output.txt");

    fout << "#include <iostream>" << endl;
    fout << "using namespace std;" << endl;
    fout << "int main(){" << endl;

    for (int i = 0; i < n ; i ++){

        if (instructions[i].name == "close"){
            fout << endl << "}" << endl;
        }
        if (instructions[i].name == "loop"){
            fout << "for (int i = 0; i < " << instructions[i].repetitions << " ; i ++) {" << endl;
        }
        if (instructions[i].name == "print"){
            fout << "cout << " << '"' << instructions[i].text << '"' << " << endl;";
        }

    }

    fout << "}" << endl;

    fout.close();

}

int main(){
    handle_input();
    handle_output();
}