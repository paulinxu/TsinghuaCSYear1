#include <iostream>
using namespace std;

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int n;
    cin >> n; 
    int **tree;
    tree = new int*[n];

    int size = 1;
    for (int i = 0; i < n ; i ++){
        tree[i] = new int[size];
        for (int j = 0; j < size ; j++){
            cin >> tree[i][j];
        }
        size ++;
    }
    
    size = n-1;
    for (int i = n-2 ; i >= 0; i --){

        for (int j = 0; j< size; j++){
            int add = max(tree[i+1][j], tree[i+1][j+1]);
            tree[i][j] += add;
        }
        size -= 1;
    }
    
    cout << tree[0][0] << endl;


}