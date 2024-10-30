#include <iostream>
#include <vector>

using namespace std;

string PROGRAM = "program";
void containsProgram(int i, int j, vector<vector<char>> matrix, vector<vector<bool>> &important){
    int n = matrix.size(), len = PROGRAM.length();

    bool lr = true, rl = true, ud = true, du = true, ul = true, ur = true, dl = true, dr = true;
    for (int k = 0; k < len; k++){
        char curr = PROGRAM[k]; 
        if (i+k >= n || matrix[i+k][j] != curr) lr = false;
        if (i-k < 0 || matrix[i-k][j] != curr) rl = false;
        if (j+k >= n || matrix[i][j+k] != curr) ud = false;
        if (j-k < 0 || matrix[i][j-k] != curr) du = false;
        if (i+k >= n || j+k >= n || matrix[i+k][j+k] != curr) dr = false;
        if (i+k >= n || j-k < 0 || matrix[i+k][j-k] != curr) dl = false;
        if (i-k < 0 || j+k >= n || matrix[i-k][j+k] != curr) ur = false;
        if (i-k < 0 || j-k < 0 || matrix[i-k][j-k] != curr) ul = false;
    }

    for (int k = 0; k < len; k++){
        if (lr) important[i+k][j] = true;
        if (rl) important[i-k][j] = true;
        if (ud) important[i][j+k] = true;
        if (du) important[i][j-k] = true;
        if (dr) important[i+k][j+k] = true;
        if (dl) important[i+k][j-k] = true;
        if (ur) important[i-k][j+k] = true;
        if (ul) important[i-k][j-k] = true;
    }
    return;
}


int main(){
    int n;
    cin >> n;
    vector<vector<bool>> important(n, vector<bool>(n, false));
    vector<vector<char>> pMatrix(n, vector<char>(n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> pMatrix[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (pMatrix[i][j] == 'p') containsProgram(i, j, pMatrix, important);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!important[i][j]){
                cout << "*" << " ";
            }else{
                cout << pMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}