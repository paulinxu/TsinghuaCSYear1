#include <iostream>
#include <vector>

using namespace std;

struct object{
    string color;
    string shape;
};

vector<object> objects;

void create(string c, string s){
    object obj = {c, s};
    objects.push_back(obj);
}

void dup(int m, string c){
    object obj = {c, objects[m-1].shape};
    objects.push_back(obj);
}

void crash(int m){
    objects.erase(std::next(objects.begin(), m-1), std::next(objects.begin(), m)); // deletes index m-1 to index m
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

bool isSmaller(object a, object b){

    if (a.color == b.color){
        return isSmallerWord(a.shape, b.shape) ? true : false;
    }
    return isSmallerWord(a.color, b.color) ? true : false;
}

void order(){

    for (int i = 0 ; i < objects.size() ; i ++){

        object smallest = objects[i];
        int pos = i;

        for (int j = i; j < objects.size() ; j ++){
            if (isSmaller(objects[j], smallest)){
                smallest = objects[j];
                pos = j;
            }
        }

        objects[pos] = objects[i];
        objects[i] = smallest; 
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++){
        string command;
        cin >> command;
        if (command == "CREATE"){
            string c, s;
            cin >> c >> s;
            create(c,s);
        }
        if (command == "DUP"){
            int m;
            string c;
            cin >> m >> c;
            dup(m, c);
        }
        if (command == "CRASH"){
            int m;
            cin >> m;
            crash(m);
        }
        if (command == "ORDER"){
            order();
        }
    }

    for (int i = 0 ; i < objects.size() ; i ++){
        cout << objects[i].color << ' ' << objects[i].shape << endl;
    }

}