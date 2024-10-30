#include <iostream>
#include <vector>

using namespace std;

struct student{
    string name;
    int height;
};

vector<student> students;

void add(string name, int height){
    student stu = {name, height};
    students.push_back(stu);
}

void select(string n){
    for (int i = 0; i < students.size() ; i ++){
        if (students[i].name == n){
            student front = students[i];
            for(int x = 1 ; x <= i ; x ++){
                students[x] = students[x-1];
            }
            students[0] = front;
        }
    }
    // deletes index i to index i+1 (not inclusize end)
}

void leave(string n){
    for (int i = 0; i < students.size() ; i ++){
        if (students[i].name == n){
            students.erase(std::next(students.begin(), i), std::next(students.begin(), i+1));
        }
    }
    // deletes index i to index i+1 (not inclusize end)
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

bool isSmaller(student a, student b){

    if (a.height == b.height){
        return isSmallerWord(a.name, b.name) ? true : false;
    }
    return a.height < b.height ? true : false;
}

void order(){

    for (int i = 0 ; i < students.size() ; i ++){

        student smallest = students[i];
        int pos = i;

        for (int j = i; j < students.size() ; j ++){
            if (isSmaller(students[j], smallest)){
                smallest = students[j];
                pos = j;
            }
        }

        students[pos] = students[i];
        students[i] = smallest; 
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++){
        string command;
        cin >> command;
        if (command == "ADD"){
            string name;
            int height;
            cin >> name >> height;
            add(name, height);
        }
        if (command == "SELECT"){
            string name;
            cin >> name;
            select(name);
        }
        if (command == "LEAVE"){
            string name;
            cin >> name;
            leave(name);
        }
        if (command == "ORDER"){
            order();
        }
    }

    for (int i = 0 ; i < students.size() ; i ++){
        cout << students[i].name << ' ' << students[i].height << endl;
    }

}