#include <iostream>
using namespace std;

int main(){

    int qa = 0;
    int qb = 1;
    int qc = 2;
    int a,b,c;

    for (int x = 0; x<= 1 ; x++){
        for (int i = 0; i<= 2 ; i++){

        qa++, qb++, qc++;

        qa = qa % 3, qb = qb % 3, qc = qc % 3;
        
        a = (qb > qa) + (qc == qa);
        b = (qa > qb) + (qa > qc);
        c = (qc > qb) + (qb > qa);
        
        if ((qa+a)==2 && (qb+b)==2 && (qc+c)==2){
            char ordered[3];
            ordered[qa] = 'A';
            ordered[qb] = 'B';
            ordered[qc] = 'C';

            cout << ordered[0] << ' ' << ordered[1] << ' ' << ordered[2];
            
        }
        }
        qa = 2 - qa, qb = 2 - qb, qc = 2 - qc;
    }
}