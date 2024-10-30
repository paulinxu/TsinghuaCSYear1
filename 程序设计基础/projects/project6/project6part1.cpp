// 2023080050 林曈
// 计37
// 程序设计基础 1-2

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int matrix[4][4]; //matrix declared globally

int getRandom(){ // returns an integer between 1 and 20. 
    // The generation seed is created in the main() function.
    return (rand()*20/RAND_MAX)+1;
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

void compress(char direction){ // compresses the matrix
    // the direction of compression is passed in a the parameter
    // 'l' = left, 'r' = right, 'u' = up, 'd' = down 
    int a, b, r, c;
    for (a = 0; a<4 ; a++){
        int sum = 0;
        for (b = 0; b<4 ; b++){
            if (direction=='l' || direction=='r'){r = a; c = b;}
            else if (direction=='u' || direction=='d'){c = a; r = b;}
            sum += matrix[r][c];
            matrix[r][c] = 0;
        }
        if (direction=='l'){matrix[r][0] = sum;}
        else if (direction=='r'){matrix[r][3] = sum;}
        else if (direction=='u'){matrix[0][c] = sum;}
        else if (direction=='d'){matrix[3][c] = sum;}
    }
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

int main(){
    
    srand((unsigned int)time(NULL)); // generation seed

    for (int r =0 ; r<4 ; r++){ // generating the initial matrix
        for (int c=0; c<4 ; c++){
            matrix[r][c] = getRandom();
        }
    }
    
    cout << "List of commands:" << endl;
    cout << "- 'compress'" << endl;
    cout << "- 'rotate'" << endl;
    cout << "- 'stop'" << endl;
    cout << "-----------" << endl;

    
    cout << "Original Matrix:" << endl;
    printMatrix();
    
    bool running = true;

    while (running){ // continuously asking for commands until the program is stopped
        cout << "Type a command: ";
        string command;
        cin >> command;

        if (command == "compress"){
            cout << "Directions: 'l' = left, 'r' = right, 'u' = up, 'd' = down" << endl;
            cout << "Direction of compression: ";
            char direction;
            cin >> direction;
            compress(direction);
            cout << "---Compression Completed---" << endl;
            printMatrix();
            cout << endl;
        }
        else if (command == "rotate"){
            rotate();
            cout << "---Rotation Completed---" << endl;
            printMatrix();
            cout << endl;
        }
        else if (command == "stop"){
            break;
        }
        else {
            cout << "Invalid command!" << endl;
            cout << endl;
        }

    }

    cout << "---Program Stopped---" << endl;
}