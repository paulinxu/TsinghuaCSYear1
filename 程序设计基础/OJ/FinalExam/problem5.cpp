#include <iostream>

using namespace std;

int n , m ;
int ** matrix;

int ** trap;

int min(int a, int b){
    return a<b ? a:b;
}

int main(){


    cin >> n >> m;

    matrix = new int*[n];
    for (int i = 0 ; i < n ; i ++){
        matrix[i] = new int[m];
    }

    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            int val;
            cin >> val;
            matrix[i][j] = val;
        }
    }

    trap = new int*[n];
    for (int i = 0 ; i < n ; i ++){
        trap[i] = new int[m];
    }

    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            trap[i][j] = 0;
        }
    }

    int k;
    cin >> k;
    for (int i = 0 ; i < k ; i ++){
        int x, y;
        cin >> x >> y;
        trap[x-1][y-1] -= 1;
    }
    int p;
    cin >> p;
    for (int i = 0 ; i < p ; i ++){
        int x, y;
        cin >> x >> y;
        trap[x-1][y-1] += 1;
    }


    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){

            if (i == 0 && j == 0){
                matrix[i][j] = matrix[i][j];
            }
            else if (i == 0){
                matrix[i][j] += matrix[i][j-1];
                trap[i][j] += trap[i][j-1];
                if (trap[i][j] < 0){
                    matrix[i][j] = 1000000;
                }

            }
            else if (j == 0){
                matrix[i][j] += matrix[i-1][j];
                trap[i][j] += trap[i-1][j];
                if (trap[i][j] < 0){
                    matrix[i][j] = 1000000;
                }
            }
            else{
                if (trap[i][j] + trap[i-1][j] < 0){
                    matrix[i][j] += matrix[i][j-1];
                    trap[i][j] += trap[i][j-1];
                }
                else if (trap[i][j] + matrix[i][j-1] < 0){
                    matrix[i][j] += trap[i-1][j];
                    trap[i][j] += trap[i-1][j];
                }
                else{
                    if (matrix[i-1][j] < matrix[i][j-1]){
                        matrix[i][j] += matrix[i-1][j];
                        trap[i][j] += trap[i-1][j];
                    }
                    else{
                        matrix[i][j] += matrix[i][j-1];
                        trap[i][j] += trap[i][j-1];
                    }

                }
            }
            
        }
    }

    // cout << "-------"<< endl;

    // for (int i = 0 ; i < n ; i ++){
    //     for (int j = 0 ; j < m ; j ++){
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // for (int i = 0 ; i < n ; i ++){
    //     for (int j = 0 ; j < m ; j ++){
    //         cout << trap[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    if ( matrix[n-1][m-1] > 1000000){
        cout << "failed";
    }
    else{
        cout << matrix[n-1][m-1] << endl;
    }
    
}