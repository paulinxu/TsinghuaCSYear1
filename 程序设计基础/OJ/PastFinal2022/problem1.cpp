#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n , m ;
    cin >> n >> m;

    vector<bool> students(n+1, false);

    for (int i = 0; i < m ; i ++){
        int current;
        cin >> current;
        students[current] = true;
    }
    bool all = true;
    for (int i = 1; i <= n; i ++){
        if (students[i] == false){
            cout << i << ' ';
            all = false;
        }
    }
    if (all){
        cout << "ALL" ;
    }
}