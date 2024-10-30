#include <iostream>
using namespace std;

// fill

#include <vector>

// fill


int** join(int **a, int **b, int m, int n, int x, int y){

    int** temp;
    temp = new int*[x];
    for (int i = 0; i<x ; i++){
        temp[i] = new int[y];
    }

    vector<int> nums(0);
    for(int i = 0 ; i<m ; i++){
        for(int j =0 ; j<n ; j++){
            nums.push_back(a[i][j]);
            nums.push_back(b[i][j]);
        }
    }
    
    int counter = 0;
    for (int i = 0 ; i<x ; i++){
        for  (int j = 0; j<y ; j++){
            temp[i][j] = nums[counter];
            counter++;
        }
    }

    return temp;

}


int main(){

    // fill

    int ** c, ** a, ** b;
    int m, n, x, y;
    cin >> m >> n >> x >> y;

    a = new int*[m];
    for (int i = 0; i<m ; i++){
        a[i] = new int[n];
        for (int j = 0; j<n ; j++){
            cin >> a[i][j];
        }
    }

    b = new int*[m];
    for (int i = 0; i<m ; i++){
        b[i] = new int[n];
        for (int j = 0; j<n ; j++){
            cin >> b[i][j];
        }
    }

    c = new int*[x];
    for (int i = 0; i<m ; i++){
        c[i] = new int[y];
    }

    // fill

    c = join(a,b,m,n,x,y);
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}