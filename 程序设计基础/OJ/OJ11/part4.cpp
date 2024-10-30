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

int solutions(int row, int queens){

    if (row == n-1){
        for (int x = 0 ; x < n ; x++){
            if (valid(x, row) && board[x][row] != 2){
                return queens+1;
            }
        }
        return queens;
    }

    int max = 0;
    bool foundvalid = false;
    for (int x = 0 ; x < n ; x++){
        if (valid(x, row) && board[x][row] != 2){
            board[x][row] = 1;
            int temp = solutions(row+1, queens+1);
            if (temp > max){
                max = temp;
            }
            board[x][row] = 0;
            foundvalid = true;
        }
    }
    if (!foundvalid){
        int temp = solutions(row+1, queens);
        if (temp > max){
            max = temp;
        }
    }
    return max;
}

int main(){

    cin >> n;
    
    board = new int*[n];
    for (int i= 0; i<n ; i++){
        board[i] = new int[n];
        for (int j = 0; j<n ; j++){
            int a;
            cin >> a;
            if (a == 1){
                board[i][j] = 0;
            }
            else{
                board[i][j] = 2;
            }
        }
    }

    cout << solutions(0, 0);

}