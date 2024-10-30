#include <iostream> 
using namespace std;

int main(){
    int n;
    cin >> n;
    int a1 = 0;
    int a2 = 0;
    int val;
    int temp;
    for (int i = 0; i < n; i++){
        cin >> val;
        if (val > a2){ 
            a2 = val;
            if (a2 > a1){ //defining a1 as the largest value and a2 as second largest
                temp = a2;
                a2 = a1;
                a1 = temp;
            }
        }
    }
    cout << a2 << endl
    ;
}