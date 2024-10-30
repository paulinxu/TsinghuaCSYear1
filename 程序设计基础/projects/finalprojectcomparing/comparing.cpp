#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

int main(){
    ifstream a("output.txt");
    ifstream b("testresults.txt");

    for (int i = 0 ; i < 3000; i++){
        string result_a;
        string result_b;
        getline(a, result_a);
        getline(b, result_b);

        cout << result_a << "|" <<result_b << endl;

        if (!(result_a == result_b)){
            cout << "Difference on test case: " << i+1 << endl;
        }
    }
    cout << "FINISHED" << endl;

}