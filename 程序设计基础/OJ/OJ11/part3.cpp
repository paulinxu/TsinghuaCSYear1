#include <iostream>
using namespace std;

int** board, n;

bool validDiagonal(int x, int y){
    for (int i = 0; i<n; i++){
        for (int j = 0 ; j<n ; j++){
            if (i+j == x+y && board[i][j]==1){
                return false;
            }
            if (i+j>x+y){
                break;
            }
        }
    }
    int x0, y0;
    if (x >= y){
        y0 = 0;
        x0 = x-y;
    }
    else{
        y0 = y-x;
        x0 = 0;
    }
    for (int i = 0; i< n ; i++){
        if (x0 < n && y0 < n){

            if (board[x0][y0] == 1){
                return false;
            }
            x0 ++;
            y0 ++;
        }
    }
    return true;
}

bool valid(int x, int y){
    // check row
    for (int i = 0; i<n ; i ++){
        if (board[i][y] == 1){
            return false;
        }
        if (board[x][i] == 1){
            return false;
        }
    }
    if (!validDiagonal(x, y)){
        return false;
    }
    return true;
}

int solutions(int row){

    if (row == n-1){
        int row_sum = 0;
        for (int x = 0 ; x < n ; x++){
            if (valid(x, row)){
                row_sum += 1;
            }
        }
        return row_sum;
    }

    int sum = 0;
    for (int x = 0 ; x < n ; x++){
        if (valid(x, row)){
            board[x][row] = 1;
            sum += solutions(row+1);
        }
        board[x][row] = 0;
    }

    return sum;
}

int main(){

    cin >> n;
    
    board = new int*[n];
    for (int i= 0; i<n ; i++){
        board[i] = new int[n];
        for (int j = 0; j<n ; j++){
            board[i][j] = 0;
        }
    }

    cout << solutions(0);

}