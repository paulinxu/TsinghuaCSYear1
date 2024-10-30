#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int star_size = 1;
    int space_size = n-1;
    
    //drawing upper half of rhombus
    for (int i = 0; i<n ; i++){
        
        //inserting spaces
        for (int space = 0; space < space_size ; space++){
            cout << " ";
        }
        for (int star = 0; star < star_size ; star++){
            cout << "*";
        }
        cout << endl;
        space_size--;
        star_size +=2 ;
    }

    space_size++;
    star_size -=2;

    //drawing lower half
    for (int i = 0; i<n-1 ; i++){
        space_size++;
        star_size -=2;
        //inserting spaces
        for (int space = 0; space < space_size ; space++){
            cout << " ";
        }
        for (int star = 0; star < star_size ; star++){
            cout << "*";
        }
        if (i != (n-1)){
            cout << endl;
        }
    }

}