#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// SIZE is determined at runtime
// so I use a 2d pointer to allocate dynamic memory to my matrix
int SIZE;
int** matrix; 

int getRandom(int max){ // returns an integer between 1 and max. 
    // The generation seed is created in the main() function.
    return (rand()*max/RAND_MAX)+1;
}

void printMatrix(){ // prints the matrix in the required format
    for (int i = 0; i<SIZE ; i++){
        cout << "----";
    }
    cout << endl;
    for (int r =0 ; r<SIZE ; r++){
        for (int c=0; c<SIZE ; c++){
            if (matrix[r][c] == -1){
                cout << setw(3) << '*';
            }
            else{
                cout << setw(3) << matrix[r][c];
            }
            cout << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i<SIZE ; i++){
        cout << "----";
    }
    cout << endl;
}

void compress(char direction){ // compresses the matrix
    // the direction of compression is passed in a the parameter
    // 'l' = left, 'r' = right, 'u' = up, 'd' = down 
    int a, b, r, c;
    for (a = 0; a<SIZE ; a++){
        int sum = 0;
        for (b = 0; b<SIZE ; b++){
            if (direction=='l' || direction=='r'){r = a; c = b;}
            else if (direction=='u' || direction=='d'){c = a; r = b;}
            sum += matrix[r][c];
            matrix[r][c] = 0;
        }
        if (direction=='l'){matrix[r][0] = sum;}
        else if (direction=='r'){matrix[r][SIZE-1] = sum;}
        else if (direction=='u'){matrix[0][c] = sum;}
        else if (direction=='d'){matrix[SIZE-1][c] = sum;}
    }
}

void rotate(){ // rotates matrix 90 degrees clockwise with respect to bottom right element
    int** temp;
    temp = new int*[SIZE];
    for (int i = 0; i<SIZE ; i++){
        temp[i] = new int[SIZE];
    }

    for (int r = 0; r < SIZE; r++){
        for (int c = 0; c < SIZE; c++){
            temp[r][c] = matrix[SIZE-1-c][r];
        }
    }
    for (int r = 0; r < SIZE; r++){
        for (int c = 0; c < SIZE; c++){
            matrix[r][c] = temp[r][c];
        }
    }

    for (int i = 0; i<SIZE ; i++){
        delete[] temp[i];
    }
    delete[] temp;
}

void adjust_column(char c){ // moves zeros to the top of column c
    // the order of the remaining elements are maintained
    vector<int> nums(0);
    for (int r=0; r<SIZE; r++){
        if (matrix[r][c]!=0){
            nums.push_back(matrix[r][c]);
        }
    }
    for (int i=0; i<(SIZE-nums.size()); i++){
        matrix[i][c] = 0;
    }
    int a = 0;
    for (int i=(SIZE-nums.size()); i<SIZE; i++){
        matrix[i][c] = nums[a];
        a++;
    }

}

void ablation(){
    // 1. orders each column using adjust_column()
    // 2. adds pairs
    // 3. orders each column again using adjust_column()
    // 4. adds a new 2 or 4 to a zero element
    for (int c = 0; c<SIZE ;c++){
        adjust_column(c);
        for (int i=0; i<SIZE-1; i++){
            if (matrix[i][c]==matrix[i+1][c]){
                matrix[i][c] = 0;
                matrix[i+1][c]*=2;
                i++;
            }
        }
        adjust_column(c);
    }
    bool exists_zero = false;
    for (int r =0 ; r<SIZE ; r++){
        for (int c=0; c<SIZE ; c++){
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

void asterix_count(){ // sets each entry as the number of '*' surrounding it
    int count;
    for (int r=0 ; r<SIZE ; r++){
        for (int c=0; c<SIZE ; c++){
            count = 0;
            if (matrix[r][c] == 0){
                for(int a = -1; a < 2; a++){
                    for (int b = -1 ; b < 2 ; b++){
                        if (r+a>=0 && c+b>=0 && r+a<SIZE && c+b<SIZE){
                            if (matrix[r+a][c+b]==-1){
                                count += 1;
                            }
                        }
                    }
                }
                matrix[r][c] = count;
            }
        }
    }
}

string remove_space(string line){ // removes spaces from string
    string result = "";
    for (int i = 0; i<line.length(); i++){
        if (line[i] != ' ') {result += line[i];}
    }
    return result;
}
int str_to_num(string str){ // changes a number from string to int format
    int num = 0;
    int multiple = 1;
    for (int i = str.length()-1; i>=0 ; i--){
        num += (int(str[i])-48)*multiple;
        multiple *= 10;
    }
    return num;
}

bool is_Empty(ifstream& pFile) // checks if a file is empty
{
    return pFile.peek() == ifstream::traits_type::eof();
}

bool is_Valid(string num){ // checks if string can be converted to int
    if (!(num[0]=='-' || (num[0]>='0' && num[0]<='9'))){
        return false;
    }
    for (int i=1; i<num.length() ; i++){
        if (!(num[i]>='0' && num[i]<='9')){
            return false;
        }
    }
    return true;
}

using namespace std;

int main(){

    SIZE = 0;
    int RAND = 0;
    vector<string> commands(0);

    // HANDLING config.txt

    ifstream fin("config.txt");
    if (fin){
        while (!fin.eof()){
            string line;
            getline(fin, line);
            line = remove_space(line);
            if (line.substr(0,4) == "SIZE"){
                if (is_Valid(line.substr(5, line.length()))){
                    SIZE = str_to_num(line.substr(5, line.length()));
                }
            }
            if (line.substr(0,4) == "RAND"){
                if (is_Valid(line.substr(5, line.length()))){
                    RAND = str_to_num(line.substr(5, line.length()));
                }
            }
            // any line starting with '#' is disregarded
        }
        if (!(SIZE > 0)){
            cout << "Incorrect 'config.txt' format" << endl;
            SIZE = 4;
        }
        if (!(RAND > 0)){
            RAND = 0;
        }
        fin.close();
    }
    else{
        SIZE = 4;
        RAND = 0;
        cout << "Incorrect 'config.txt' format: file not found" << endl;
    }
    cout << "SIZE=" << SIZE << ", RAND=" << RAND << endl;

    // HANDLING cmd.txt

    bool cmd_exists = true;
    fin.open("cmd.txt");
    bool isEmpty_cmd = is_Empty(fin);

    if (fin){
        while (!fin.eof()){
            string line;
            getline(fin, line);
            commands.push_back(remove_space(line));
        }
        fin.close();
    }
    else{
        cout << "'cmd.txt' not found" << endl;
        cmd_exists = false; 
    }

    // GENERATING MATRIX

    srand((unsigned int)time(NULL)); // generation seed

    matrix = new int*[SIZE];
    for (int i = 0; i<SIZE; i++){
        matrix[i] = new int[SIZE];
    }

    for (int r =0 ; r<SIZE ; r++){ // filling the initial matrix
        for (int c=0; c<SIZE ; c++){
            matrix[r][c] = 0;
        }
    }

    int num;
    if (!(RAND > 0)){
        num = 1;
    }
    else {
        num = SIZE*SIZE*RAND/100;
    }

    int count = 0;
    while (count < num){ // randomly selecting elements to be filled
        int max_power = 4;
        if (num == 1){
            max_power = 2;
        }
        int r = getRandom(SIZE)-1;
        int c = getRandom(SIZE)-1;
        if (matrix[r][c] == 0){
            matrix[r][c] = pow(2, getRandom(max_power));
            count++;
        }
    }

    // MATRIX OPERATIONS

    if (!cmd_exists){
        for (int r =0 ; r<SIZE ; r++){
            for (int c=0; c<SIZE ; c++){
                if (matrix[r][c] != 0){
                    matrix[r][c] = -1;
                }
            }
        }
        asterix_count();
        cout << "FINAL MATRIX:" << endl;
        printMatrix();
    }
    else if (isEmpty_cmd && cmd_exists){
        for (int r =0 ; r<SIZE ; r++){
            for (int c=0; c<SIZE ; c++){
                if (matrix[r][c] != 0){
                    matrix[r][c] = getRandom(20);
                }
            }
        }
        cout << "FINAL MATRIX:" << endl;
        printMatrix();
    }
    else {
        int counter = 1;
        cout << "INITIAL MATRIX:" << endl;
        printMatrix();
        for (int i = 0 ; i<commands.size() ; i++){
            if (commands[i][0] == 'r'){
                cout << counter << ". ROTATION:"<< endl;
                rotate();
                printMatrix();
                counter++;
            }
            else if (commands[i][0] == 'a'){
                cout << counter << ". ABLATION:"<< endl;
                ablation();
                printMatrix();
                counter++;
            }
            else if (commands[i][0] == 'c'){
                cout << counter << ". COMPRESSION with direction " << commands[i][1] << ":" << endl;
                compress(commands[i][1]);
                printMatrix();
                counter++;
            }
            else if (commands[i][0] == 'Q'){
                cout << counter << ".QUIT" << endl;
                break;
            }
        }
    }

    // END 

    for (int i = 0; i < SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}