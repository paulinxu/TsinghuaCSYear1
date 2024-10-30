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

    tree[1][0] += tree[0][0];
    tree[1][1] += tree[0][0];

    
    if (n>2){
        size = 3;
        for (int i = 2 ; i < n ; i ++){

            tree[i][0] += tree[i-1][0];
            tree[i][size-1] += tree[i-1][size-2];

            for (int j = 1; j< size-1; j++){
                int add = max(tree[i-1][j-1], tree[i-1][j]);
                tree[i][j] += add;
            }
            size += 1;
        }
    }

    int maximum = 0;
    
    for (int j = 0; j<n ;j++){
        if (tree[n-1][j] > maximum){
            maximum = tree[n-1][j];
        }
    }
    cout << maximum << endl;


}