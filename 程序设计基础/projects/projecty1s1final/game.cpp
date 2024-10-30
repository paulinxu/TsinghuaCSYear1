// add info here
// 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void inbox(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){ // command 0
    *current = input[*input_counter];
    *isCurrent = true;
    *input_counter += 1;
}

void outbox(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){ // command 1
    if (!*isCurrent){
        cout << "ERROR: NO CURRENT ITEM" << endl;
        return;
    }
    int temp = *current;
    output.push_back(temp);
    *isCurrent = false;
}

void add(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){
    if (!*isCurrent){
        cout << "ERROR: NO CURRENT ITEM" << endl;
        return;
    }
    if (!free_blocks[x]){
        cout << "ERROR: NO ITEM IN INDICATED SPACE" << endl;
        return;
    }
    *current = *current + free_blocks[x];
}

void sub(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){
    if (!*isCurrent){
        cout << "ERROR: NO CURRENT ITEM" << endl;
        return;
    }
    if (!free_blocks[x]){
        cout << "ERROR: NO ITEM IN INDICATED SPACE" << endl;
        return;
    }
    *current = *current - free_blocks[x];
}

void copyto(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){
    if (!*isCurrent){
        cout << "ERROR: NO CURRENT ITEM" << endl;
        return;
    }
    // add error 2 prenvention
    free_blocks[x] = *current;
}

void copyfrom(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){
    // add error prevention
    *current = free_blocks[x];
    *isCurrent = true;
}

void jump(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){
    *command_counter = x-1; // x-1 because look int game() does command_counter++ fight after jump is called
}

void jumpifzero(int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter){
    if (*current == 0){
        *command_counter = x-1;
    }
}

typedef void (*functions_typedef) (int *current, bool*isCurrent, int input[], int *input_counter, vector<int> &output, int free_blocks[], int x, int *command_counter);

functions_typedef functions[] = { inbox, outbox, add, sub, copyto, copyfrom, jump, jumpifzero };

bool check(int answer_length, int answer[], vector<int> output){
    bool correct = true;
    for (int  i = 0; i < answer_length; i++){
        if (output[i] != answer[i]){
            correct = false;
            break;
        }
    }
    if (answer_length != output.size()){
        correct = false;
    }

    if (correct){
        cout << "CORRECT ANSWER" << endl;
    }
    else {
        cout << "WRONG ANSWER" << endl;
    }
    return correct;
}

void game(int level, string user_input_file){

    int input_length, *input, answer_length, *answer, available_commands_length, *available_commands, free_blocks_length, *free_blocks;

    // GET LEVEL SETTINGS

    ifstream fin("levelsettings.txt");
    if (fin){
        while (!fin.eof()){
            string line;
            getline(fin, line);
            if((line.substr(0,5) == "level") && (line[6] == '0' + level)){// only levels 0-9 for now

                fin >> input_length;
                input = new int[input_length];
                for (int i = 0; i < input_length ; i ++){
                    fin >> input[i];
                }

                fin >> answer_length;
                answer = new int[answer_length];
                for (int i = 0; i < answer_length ; i ++){
                    fin >> answer[i];
                }

                fin >> available_commands_length;
                available_commands = new int[available_commands_length];
                for (int i = 0; i < available_commands_length ; i ++){
                    fin >> available_commands[i];
                }

                fin >> free_blocks_length;
                free_blocks = new int[free_blocks_length];
                
                break;
            } 
        }
    }

    fin.close();

    //GET USER INPUT COMMANDS

    int command_length, *commands, *arguments;

    fin.open(user_input_file);

    if (fin){
        while (!fin.eof()){
            string line;
            getline(fin, line);
            if (line == "ENTER_COMMANDS_BELOW:"){
                fin >> command_length;
                commands = new int[command_length];
                arguments = new int[command_length];
                for (int i = 0 ; i < command_length ; i ++){
                    fin >> commands[i] >> arguments[i];
                }
                break;
            }
        }
    }

    fin.close();
    
    // START GAME

    int input_counter = 0;
    int command_counter = 0;

    bool isCurrent = false;
    int current = 0;


    vector<int> output;

    while (input_counter <= input_length && command_counter < command_length){

        functions[commands[command_counter]](&current, &isCurrent, input, &input_counter, output, free_blocks, arguments[command_counter], &command_counter);
        command_counter ++;

    }

    // CHECK ANSWER

    cout << "Correct answer: ";
    for (int i = 0 ; i < answer_length ; i++){
        cout << answer[i] << ' ';
    }
    cout << endl;
    cout << "Your answer   : ";
    for (int i = 0 ; i < output.size() ; i++){
        cout << output[i] << ' ';
    }
    cout << endl;

    check(answer_length, answer, output);

    // DELETE ARRAYS
    delete[] input;
    delete[] answer;
    delete[] available_commands;
    delete[] free_blocks;
    delete[] commands;
    delete[] arguments;
}

int main(){
    while(true){

        int level = 1;
        int max_level;

        ifstream fin("progress.txt");
        if (fin){ fin >> max_level; }
        fin.close();

        cout << "Available levels: ";
        for (int i = 1; i <= max_level+1 ; i++){
            cout << i << ' ';
        }
        cout << endl;

        cout << "Choose a level: ";
        cin >> level;

        game(level, "userinput.txt");

        int quit_game = 0;
        cout << "Do you want to quit the game? (0/1): ";
        cin >> quit_game;
        if (quit_game == 1){
            break;
        }
    }
    cout << "PROGRAM TERMINATED" << endl;
    
}