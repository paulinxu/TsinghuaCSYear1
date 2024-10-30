#include <iostream>
#include <vector>

using namespace std;

struct student{
    int energy;
};

vector<student> students;

void donate(int x, int y){
    int amount = students[x].energy/2;
    students[x].energy -= amount;
    students[y].energy += amount;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ;i ++){
        student current;
        cin >> current.energy;
        students.push_back(current);
    }
    for (int i = 0 ; i < m; i++){
        int x, y;
        cin >> x >> y;
        donate(x, y);
    }



    int min = students[0].energy;

    for (int i = 0 ; i < n ; i++){
        if (students[i].energy < min){
            min = students[i].energy;
        }
    }

    int max = 0;

    for (int i = 0 ; i < n ; i++){
        if (students[i].energy > max){
            max = students[i].energy;
        }
    }

    cout << max - min << endl;

}