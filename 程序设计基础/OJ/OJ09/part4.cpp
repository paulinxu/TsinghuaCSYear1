#include <iostream>
using namespace std;

void printMatrix(int ** matrix, int n){
    for (int i= 0; i < n ; i++){
        for (int j = 0; j<n ; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int n, ** matrix;
    cin >> n;

    matrix = new int*[n];
    for (int i=0 ; i<n ; i++){
        matrix[i] = new int[n];
        for (int j = 0; j<n; j++){
            matrix[i][j] = 0;
        }
    }

    // fill row 0 and last
    int value = 1;
    for (int c = 0; c<n ; c++){
        matrix[0][c] = value;
        matrix[n-1][n-1-c] = n*n - (value-1);
        if (c%2==0){
            value += 2*(c+1);
        }
        else{
            value++;
        }
    }

    // upper left
    for (int r = 1; r<n-1;r++){
        for(int c = 0; c<n-r ; c++){
            if (r%2 == 1){
                if (c%2==0){
                    matrix[r][c] = matrix[r-1][c+1] -1;
                }
                else{
                    matrix[r][c] = matrix[r-1][c+1] +1;
                }
            }
            else{
                if (c%2==1){
                    matrix[r][c] = matrix[r-1][c+1] -1;
                }
                else{
                    matrix[r][c] = matrix[r-1][c+1] +1;
                }
            }
        }
    }

    // bottom right

    for (int r = n-1-1; r>0; r--){
        for (int c = n-1 ; c>1 ; c--){
            if ((n-r)%2 == 1){
                if ((n-c)%2==0){
                    matrix[r][c] = matrix[r+1][c-1] +1;
                }
                else{
                    matrix[r][c] = matrix[r+1][c-1] -1;
                }
            }
            else{
                if ((n-c)%2==1){
                    matrix[r][c] = matrix[r+1][c-1] +1;
                }
                else{
                    matrix[r][c] = matrix[r+1][c-1] -1;
                }
            }
        }
    }

    printMatrix(matrix, n);

}