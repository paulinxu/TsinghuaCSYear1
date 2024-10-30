#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> output;

int main(){
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        vector<char> row;
        string line;
        vector<bool> orow;
        cin >> line;
        for (int j = 0 ; j < n ; j ++){
            row.push_back(line[j]);
            orow.push_back(false);
        }
        matrix.push_back(row);
        output.push_back(orow);
    }

    string program = "program";
    string margrop = "margorp";

    for (int r = 0 ; r < n ; r ++){
        for (int c = 0 ; c <= n -7 ; c++){
            
            bool valid = true;
            for (int i = c; i < c+7 ; i++){
                //cout << matrix[r][i] << ' ' << program[i-c] << endl;
                if (matrix[r][i] != program[i-c]){
                    valid = false;
                    break;
                }
            }
            if (valid){
                cout << "found" << endl;
                for (int i = c; i < c+7 ; i++){
                    output[r][i] = true; 
                }
            }
            valid = true;
            for (int i = c; i < c+7 ; i++){
                //cout << matrix[r][i] << ' ' << program[i-c] << endl;
                if (matrix[r][i] != margrop[i-c]){
                    valid = false;
                    break;
                }
            }
            if (valid){
                cout << "found" << endl;
                for (int i = c; i < c+7 ; i++){
                    output[r][i] = true; 
                }
            }

        }
    }

    for (int c = 0 ; c < n ; c ++){
        for (int r = 0 ; r <= n -7 ; r++){
            
            bool valid = true;
            for (int i = r; i < r+7 ; i++){
                //cout << matrix[i][c] << ' ' <<margrop[i-r] << endl;
                if (matrix[i][c] != margrop[i-r]){
                    valid = false;
                    break;
                }
            }
            if (valid){
                cout << "found" << endl;
                for (int i = r; i < r+7 ; i++){
                    output[i][c] = true; 
                }
            }

            bool valid = true;
            for (int i = r; i < r+7 ; i++){
                //cout << matrix[i][c] << ' ' <<margrop[i-r] << endl;
                if (matrix[i][c] != program[i-r]){
                    valid = false;
                    break;
                }
            }
            if (valid){
                cout << "found" << endl;
                for (int i = r; i < r+7 ; i++){
                    output[i][c] = true; 
                }
            }

        }
    }


    for (int r = 0 ; r < n ; r ++){
        for (int c = 0 ; c < n ; c++){
            if (output[r][c] == true){
                cout << matrix[r][c];
            }
            else{
                cout << '*';
            }
        }
        cout << endl;
    }

}