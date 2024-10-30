#include <iostream>
using namespace std;

int n, m, k;
int ** points;

bool checktrip(int pn, int pm){

    for (int point = 0; point< k ; point++){
        if (points[point][0] == pn && points[point][1] == pm){
            return true;
        }
    }

    return false;
}

int solutions(int n1, int m1, int n2, int m2, int pren, int prem){
    
    if (pren >= 0 && prem >= 0){
        if (m1 - prem == 2){
            if (checktrip(pren, prem+1)){
                return 0;
            }
        }
        if (m1 - prem == 1){
            if (checktrip(pren+1, prem)){
                return 0;
            }
        }
        if (m1 - prem == -1){
            if (checktrip(pren+1, prem)){
                return 0;
            }
        }
        if (m1 - prem == -2){
            if (checktrip(pren, prem-1)){
                return 0;
            }
        }
    }
    

    for (int point = 0; point< k ; point++){
        if (points[point][0] == n1 && points[point][1] == m1){
            return 0;
        }
    }

    if (n1 > n2 || m1 > m2){
        return 0;
    }
    if (n1 < 0 || m1 < 0){
        return 0;
    }
    if (n1 == n2 && m1 == m2){
        return 1;
    }
    
    return solutions(n1+1, m1+2 , n2, m2, n1, m1) + solutions(n1+2, m1+1 , n2, m2, n1, m1) + solutions(n1+1, m1-2 , n2, m2, n1, m1) + solutions(n1+2, m1-1 , n2, m2, n1, m1); 
}

int main(){
    cin >> n >> m >> k;

    points = new int*[k];
    for (int i = 0 ; i < k ; i++){
        points[i] = new int[2];
        cin >> points[i][0] >> points[i][1];
    }

    cout << solutions(0, 0, n, m, -1, -1);
}