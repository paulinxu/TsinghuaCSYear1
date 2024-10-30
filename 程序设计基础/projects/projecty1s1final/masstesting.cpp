// add info here
// 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

ifstream fin("testcases2.txt");

ofstream fout("testresultsnew.txt");


vector<string> results;

void inbox(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) { // command 0
    *current = input[*input_counter];
    *isCurrent = true;
    *input_counter += 1;
}

void outbox(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) { // command 1
    if (!*isCurrent) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    int temp = *current;
    output.push_back(temp);
    *isCurrent = false;
}

void add(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) {
    if (!*isCurrent || x < 0 || x >= free_blocks_length || filled_free_blocks[x] == false) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    *current = *current + free_blocks[x];
}

void sub(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) {
    if (!*isCurrent || x < 0 || x >= free_blocks_length || filled_free_blocks[x] == false) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    *current = *current - free_blocks[x];
}

void copyto(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) {
    if (!*isCurrent || x < 0 || x >= free_blocks_length) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    free_blocks[x] = *current;
    filled_free_blocks[x] = true;
}

void copyfrom(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) {
    if (x < 0 || x >= free_blocks_length || filled_free_blocks[x] == false) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    *current = free_blocks[x];
    *isCurrent = true;
}

void jump(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) {
    if (x<1 || x > command_length) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    *command_counter = x - 2; // -1 because game() does command_counter++, -1 for index translation
}

void jumpifzero(int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]) {
    if (!*isCurrent || x<1 || x > command_length) {
        results.push_back("Error on instruction " + to_string(*command_counter + 1));
        *error = true;
        return;
    }
    if (*current == 0  && *isCurrent == true) {
        *command_counter = x - 2;
    }
}

typedef void (*functions_typedef) (int* current, bool* isCurrent, int input[], int* input_counter, vector<int>& output, int free_blocks[], int x, int* command_counter, bool* error, int command_length, int free_blocks_length, bool filled_free_blocks[]);

functions_typedef functions[] = { inbox, outbox, add, sub, copyto, copyfrom, jump, jumpifzero };

bool check(int answer_length, int answer[], vector<int> output) {
    bool correct = true;
    if (answer_length == output.size()) {
        for (int i = 0; i < answer_length; i++) {
            if (output[i] != answer[i]) {
                correct = false;
                break;
            }
        }
    }
    else {
        correct = false;
    }

    if (correct) {
        results.push_back("Success");
    }
    else {
        results.push_back("Fail");
    }
    return correct;
}

bool isValidCommand(int available_commands_length, int available_commands[], int command) {
    for (int i = 0; i < available_commands_length; i++) {
        if (command == available_commands[i]) {
            return true;
        }
    }
    return false;
}

void game(int level, int command_length, int commands[], int arguments[],
    int input_length, int input[], int answer_length, int answer[], int available_commands_length,
    int available_commands[], int free_blocks_length
) {
    // OJ VERSION BELOW

    // START GAME
    int* free_blocks;
    free_blocks = new int[free_blocks_length];

    bool* filled_free_blocks;
    filled_free_blocks = new bool[free_blocks_length];
    for (int i = 0; i < free_blocks_length; i++) { filled_free_blocks[i] = false; }

    int input_counter = 0;
    int command_counter = 0;

    bool isCurrent = false;
    int a = 0;

    // for (int i = 0; i < command_length ; i++){
    //     cout << commands[i] << ' ' << arguments[i] << endl;
    // }

    vector<int> output;

    while (input_counter <= input_length && command_counter < command_length) {

        if (!isValidCommand(available_commands_length, available_commands, commands[command_counter])) {
            results.push_back("Error on instruction " + to_string(command_counter +1));
            return;
        }

        bool error = false;

        functions[commands[command_counter]](&a, &isCurrent, input, &input_counter, output, free_blocks, arguments[command_counter], &command_counter, &error, command_length, free_blocks_length, filled_free_blocks);

        if (error) {
            return;
        }

        command_counter++;

    }
    // CHECK ANSWER

    // cout << "Correct answer: ";
    // for (int i = 0 ; i < answer_length ; i++){
    //     cout << answer[i] << ' ';
    // }
    // cout << endl;
    // cout << "Your answer   : ";
    // for (int i = 0 ; i < output.size() ; i++){
    //     cout << output[i] << ' ';
    // }
    // cout << endl;

    check(answer_length, answer, output);

}

int main(){

    int cases;
    fin >> cases;
    for (int y = 0; y < cases ; y++){

        int x, m;
        int *commands;
        int *arguments;

        fin >> x;
        fin >> m;

        commands = new int[m];
        arguments = new int[m];

        for (int i = 0; i < m; i++) {
            string text;
            fin >> text;
            if (text == "inbox") {
                commands[i] = 0;
                arguments[i] = 0;
            }
            else if (text == "outbox") {
                commands[i] = 1;
                arguments[i] = 0;
            }
            else if (text == "add") {
                commands[i] = 2;
                fin >> arguments[i];
            }
            else if (text == "sub") {
                commands[i] = 3;
                fin >> arguments[i];
            }
            else if (text == "copyto") {
                commands[i] = 4;
                fin >> arguments[i];
            }
            else if (text == "copyfrom") {
                commands[i] = 5;
                fin >> arguments[i];
            }
            else if (text == "jump") {
                commands[i] = 6;
                fin >> arguments[i];
            }
            else if (text == "jumpifzero") {
                commands[i] = 7;
                fin >> arguments[i];
            }
            else{
                results.push_back("Error on instruction " + to_string(i + 1));
                continue;
            }

            if (!fin) {
                results.push_back("Error on instruction " + to_string(i + 1));
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }   
        }

        // if (y+1 == 1082){
        //     for (int z = 0; z < m ; z++){
        //         cout << commands[z] << ' ' << arguments[z] << endl;
        //     }

        // }

        cout << y+1 << endl;
        
        // cout << x << endl;
        // for (int i = 0; i < m ; i++){
        //     cout << commands[i] << ' ' << arguments[i] << endl;
        // }

        if (results.size() == y){
            if (x == 1) {
                int input[] = { 1,2 };
                int answer[] = { 1,2 };
                int available_commands[] = { 0,1 };
                game(x, m, commands, arguments, 2, input, 2, answer, 2, available_commands, 0);
            }
            if (x == 2) {
                int input[] = { 3,9,5,1,-2,-2,9,-9 };
                int answer[] = { -6,6,4,-4,0,0,18,-18 };
                int available_commands[] = { 0,1,2,3,4,5,6,7 };
                game(x, m, commands, arguments, 8, input, 8, answer, 8, available_commands, 3);
            }
            if (x == 3) {
                int input[] = { 6,2,7,7,-9,3,-3,-3 };
                int answer[] = { 7,-3 };
                int available_commands[] = { 0,1,2,3,4,5,6,7 };
                game(x, m, commands, arguments, 8, input, 2, answer, 8, available_commands, 3);
            }
        }
    }

    for (int i = 0 ; i < results.size(); i++){
        fout << results[i] << endl;
    }
}