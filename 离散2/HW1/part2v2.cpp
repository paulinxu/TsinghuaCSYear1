#include <iostream>
#include <vector>

using namespace std;

int n, m, s, t, k;
int **matrix;
int **result;

void printm(int **x) 
{
    for (int i = 0 ; i < n ; i++) 
    {
        for (int j = 0 ; j < n ; j++) 
        {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }
}

void multiply(int **a, int **b, int **res) 
{
    int **temp = new int*[n];
    for (int i = 0 ; i < n ; i++) 
    {
        temp[i] = new int[n]();
    }

    for (int i = 0 ; i < n ; i++) 
    {
        for (int j = 0 ; j < n ; j++) 
        {
            temp[i][j] = 0;
            for (int k = 0 ; k < n ; k++) 
            {
                temp[i][j] = (temp[i][j] + (long long)a[i][k] * b[k][j]) % 1000003;
            }
        }
    }

    for (int i = 0 ; i < n ; i++) 
    {
        for (int j = 0 ; j < n ; j++) 
        {
            res[i][j] = temp[i][j];
        }
    }

    for (int i = 0 ; i < n ; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
}

int main() 
{
    cin >> n >> m >> s >> t >> k;

    matrix = new int*[n];
    result = new int*[n];

    for (int i = 0 ; i < n ; i++) 
    {
        matrix[i] = new int[n];
        result[i] = new int[n];
        result[i][i] = 1;
    }

    for (int i = 0 ; i < m ; i++) 
    {
        int u, v;
        cin >> u >> v;
        matrix[u-1][v-1]++;
    }

    while (k > 0) 
    {
        if (k % 2 == 1) {
            multiply(result, matrix, result);
        }
        multiply(matrix, matrix, matrix);
        k /= 2;
    }

    cout << result[s-1][t-1] << endl;

    return 0;
}