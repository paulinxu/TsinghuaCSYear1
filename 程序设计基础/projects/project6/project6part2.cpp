// 2023080050 林曈
// 计37
// 程序设计基础 1-2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

int matrix[4][4]; //matrix declared globally

int getRandom(int max){ // returns an integer between 1 and max. 
    // The generation seed is created in the main() function.
    return (rand()*max/RAND_MAX)+1;
}

void printMatrix(){ // prints the matrix in the required format
    cout << "----------------" << endl;
    for (int r =0 ; r<4 ; r++){
        for (int c=0; c<4 ; c++){
            printf("%3d", matrix[r][c]);
            cout << ' ';
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

void rotate(){ // rotates matrix 90 degrees clockwise with respect to bottom right element
    int temp[4][4];
    for (int r = 0; r < 4; r++){
        for (int c = 0; c < 4; c++){
            temp[r][c] = matrix[3-c][r];
        }
    }
    for (int r = 0; r < 4; r++){
        for (int c = 0; c < 4; c++){
            matrix[r][c] = temp[r][c];
        }
    }
}

void adjust_column(char c){ // moves zeros to the top of column c
    // the order of the remaining elements are maintained
    vector<int> nums(0);
    for (int r=0; r<4; r++){
        if (matrix[r][c]!=0){
            nums.push_back(matrix[r][c]);
        }
    }
    for (int i=0; i<(4-nums.size()); i++){
        matrix[i][c] = 0;
    }
    int a = 0;
    for (int i=(4-nums.size()); i<4; i++){
        matrix[i][c] = nums[a];
        a++;
    }

}

void ablation(){
    // 1. orders each column using adjust_column()
    // 2. adds pairs
    // 3. orders each column again using adjust_column()
    // 4. adds a new 2 or 4 to a zero element
    for (int c = 0; c<4 ;c++){
        adjust_column(c);
        for (int i=0; i<3; i++){
            if (matrix[i][c]==matrix[i+1][c]){
                matrix[i][c] = 0;
                matrix[i+1][c]*=2;
                i++;
            }
        }
        adjust_column(c);
    }
    bool exists_zero = false;
    for (int r =0 ; r<4 ; r++){
        for (int c=0; c<4 ; c++){
            if (matrix[r][c] == 0){
                exists_zero = true;
                break;
            }
        }
    }
    if (exists_zero){
        while(true){
            int r = getRandom(4)-1;
            int c = getRandom(4)-1;
            if (matrix[r][c] == 0){
                matrix[r][c] = pow(2, getRandom(2));
                break;
            }
        }
    }
}

int main(){
    
    // selecting generating ratio
    float ratio;
    cout << "Choose a generation ratio (0<x<1): ";
    cin >> ratio;
    cout << endl;    
    
    int num = 16*ratio;

    srand((unsigned int)time(NULL)); // generation seed

    for (int r =0 ; r<4 ; r++){ // generating the initial matrix
        for (int c=0; c<4 ; c++){
            matrix[r][c] = 0;
        }
    }
    int count = 0;
    while (count < num){ // randomly selecting elements to be filled
        // I am filling these elements with 2 or 4, but these can be adjusted below
        int max_power = 2;
        int r = getRandom(4)-1;
        int c = getRandom(4)-1;
        if (matrix[r][c] == 0){
            matrix[r][c] = pow(2, getRandom(max_power));
            count++;
        }
    }

    // user interaction

    cout << "List of commands:" << endl;
    cout << "- 'ablation' or 'a'" << endl;
    cout << "- 'rotate' or 'r'" << endl;
    cout << "- 'Q' (quit)" << endl;
    cout << endl;

    printMatrix();
    cout << endl;
    
    bool running = true;

    while (running){
        cout << "Type a command: ";
        string command;
        cin >> command;

        if (command == "rotate" || command == "r"){
            // goes up 8 lines so that the previous printed matrix is overwritten
            for (int i=0; i<8;i++){ 
                cout << "\e[A";
            }
            rotate();
            printMatrix();
            cout << endl;
        }
        else if (command == "ablation" || command == "a"){
            for (int i=0; i<8;i++){
                cout << "\e[A";
            }
            ablation();
            printMatrix();
            cout << endl;
        }
        else if (command == "Q"){
            break;
        }
        else {
            for (int i=0; i<8;i++){
                cout << "\e[A";
            }
            printMatrix();
            cout << endl;
        }

    }
    cout << "---Program Stopped---" << endl;
}