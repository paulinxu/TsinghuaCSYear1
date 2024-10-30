#include <iostream>
#include <vector>
using namespace std;



int find(int step, vector<int> arr){
    if (arr[step] == 1){
        return 0;
    }
    else if (step == 0){
        return 1;
    }
    else if (step<0){
        return 0;
    }
    else{
        return find(step-1, arr) + find(step-2, arr) + find(step-3, arr);
    }
}

int main(){

    int h, n;
    
    vector<int> arr(0);

    cin >> h >> n;

    int step;
    for (int i = 0; i<h+1 ; i++){
        arr.push_back(0);
    }

    for (int i = 0 ; i<n ; i++){
        cin >> step;
        arr[step] = 1; 
    }

    arr[0] = -1;

    // for (int i = 0; i<h+1 ; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    
    cout << find(h, arr) << endl;
}