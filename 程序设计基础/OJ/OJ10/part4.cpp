#include <iostream>
using namespace std;

int n, m, k;
int ** points; 

int solutions(int n1, int m1, int n2, int m2){

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
    
    return solutions(n1+1, m1+2 , n2, m2) + solutions(n1+2, m1+1 , n2, m2) + solutions(n1+1, m1-2 , n2, m2) + solutions(n1+2, m1-1 , n2, m2); 
}

int main(){
    cin >> n >> m >> k;

    points = new int*[k];
    for (int i = 0 ; i < k ; i++){
        points[i] = new int[2];
        cin >> points[i][0] >> points[i][1];
    }

    cout << solutions(0, 0, n, m);
}