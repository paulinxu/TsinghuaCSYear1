#include <iostream>
#include <vector>

using namespace std;

int n;

string program = "program";
string margrop = "margorp";

vector<vector<char>> matrix;
vector<vector<bool>> output;

void hleft(int i, int j){
    int start = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        j++;
    }
    if (text == program){
        for (int x = start; x < j; x++){
            output[i][x] = true;
        }
    }
}

void hright(int i, int j){
    int start = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        j--;
    }
    if (text == program){
        for (int x = start; x > j; x--){
            output[i][x] = true;
        }
    }
}

void vdown(int i, int j){
    int start = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        i++;
    }
    if (text == program){
        for (int x = start; x < j; x++){
            output[x][j] = true;
        }
    }
}

void vup(int i, int j){
    int start = i;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        i--;
    }
    cout << text << endl;
    if (text == program){
        for (int x = start; x > i; x--){
            output[x][j] = true;
        }
    }
}

void diagonal1(int i, int j){
    int starti = i;
    int startj = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        i++;
        j++;
    }
    if (text == program){
        for (int x = 0; x < 7; x++){
            output[starti+x][startj+x] = true;
        }
    }
}
void diagonal2(int i, int j){
    int starti = i;
    int startj = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        i++;
        j--;
    }
    if (text == program){
        for (int x = 0; x < 7; x++){
            output[starti+x][startj-x] = true;
        }
    }
}
void diagonal3(int i, int j){
    int starti = i;
    int startj = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        i--;
        j--;
    }
    if (text == program){
        for (int x = 0; x < 7; x++){
            output[starti-x][startj-x] = true;
        }
    }
}
void diagonal4(int i, int j){
    int starti = i;
    int startj = j;
    string text = "";
    while (i<n && i >=0 && j<n && j >=0 && text.length() < 7){
        text += matrix[i][j];
        i--;
        j++;
    }
    if (text == program){
        for (int x = 0; x < 7; x++){
            output[starti-x][startj+x] = true;
        }
    }
}



int main(){
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

    for (int r = 0 ; r < n ; r ++){
        for (int c = 0 ; c < n ; c++){
            if (matrix[r][c] == 'p'){
                hleft(r,c);
                hright(r,c);
                vdown(r,c);
                vup(r,c);
                diagonal1(r,c);
                diagonal2(r,c);
                diagonal3(r,c);
                diagonal4(r,c);
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