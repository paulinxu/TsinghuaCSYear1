#include <iostream>
#include <vector>

using namespace std;

struct dna{
    string type;
};

vector<dna> sequence;

void add(string type){
    dna x = {type};
    sequence.push_back(x);
}

void select(int index, string txt){
    sequence[index-1].type = txt;
}

void cut(int m){
    sequence.erase(std::next(sequence.begin(), m-1), std::next(sequence.begin(), m)); // deletes index m-1 to index m
}

bool isSmallerWord(string a, string b){
    int i = 0;
    while (i < a.length() && i < b.length()){
        if (a[i] < b[i]){
            return true;
        }
        else if (a[i] > b[i]){
            return false;
        }
        i++;
    }
    if (a.length() < b.length()){
        return true;
    }
    return false;
}

bool isSmaller(dna a, dna b){

    return isSmallerWord(a.type, b.type) ? true : false;
}

void order(int start, int end){

    for (int i = start-1 ; i < end ; i ++){

        dna smallest = sequence[i];
        int pos = i;

        for (int j = i; j < end ; j ++){
            if (isSmaller(sequence[j], smallest)){
                smallest = sequence[j];
                pos = j;
            }
        }

        sequence[pos] = sequence[i];
        sequence[i] = smallest; 
    }
}

void check(){

    int size = sequence.size();

    bool condition1 = false;
    if (size >= 3){
        bool condition1 = true;
        for (int i = size-1 ; i >= size-3 ; i --){
            if (sequence[i].type != "TA"){
                condition1 = false;
            }
        }

        if (condition1){
            for (int i = size-1 ; i >= size -3 ; i --){
                sequence[i].type = "GC";
            }
        }
    }

    bool at = false;
    bool ta = false;
    bool gc = false;
    if (size >= 3){
        
        for (int i = size-1 ; i >= size -3 ; i --){
            if (sequence[i].type == "AT"){
                at = true;
            }
            if (sequence[i].type == "TA"){
                ta = true;
            }
            if (sequence[i].type == "GC"){
                gc = true;
            }
        }
        if (at && ta && gc){
            for (int i = size-1 ; i >= size -3 ; i --){
                sequence[i].type = "GC";
            }
        }
    }

}

int main(){

    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++){
        string command;
        cin >> command;
        if (command == "ADD"){
            string c;
            cin >> c;
            add(c);
            check();
        }
        if (command == "SELECT"){
            int m;
            string c;
            cin >> m >> c;
            select(m, c);
        }
        if (command == "CUT"){
            int m;
            cin >> m;
            cut(m);
        }
        if (command == "ORDER"){
            int start, end;
            cin >> start >> end;
            order(start, end);
        }
        // for (int i = 0 ; i < sequence.size() ; i ++){
        //     cout << sequence[i].type << endl;
        // }
        // cout << "----------" << endl;
    }


    for (int i = 0 ; i < sequence.size() ; i ++){
        cout << sequence[i].type << endl;
    }

}