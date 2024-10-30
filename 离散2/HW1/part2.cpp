#include <iostream>
#include <vector>

using namespace std;

int n, m, s, t, k;
int **matrix;
int **matrix_copy;

void printm(int **x)
{
    for (int i = 0; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }
}

void copy(int **from, int **to)
{
    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            to[i][j] = from[i][j];
        }
    }
}

void multiply()
{
    int **temp;
    temp = new int*[n];
    for (int i = 0; i < n ; i ++)
    {
        temp[i] = new int[n];
        for (int j = 0 ; j < n ; j ++)
        {
            temp[i][j] = 0;
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            int sum = 0;
            for (int k = 0 ; k < n ; k++)
            {
                sum += matrix[i][k] * matrix_copy[k][j] % 1000003;
            }
            temp[i][j] = sum;
        }
    }

    copy(temp, matrix);

    for (int i = 0; i < n; i++) {
        delete[] temp[i];
        }
    delete[] temp;
}

int main()
{
    cin >> n >> m >> s >> t >> k;

    matrix = new int*[n];
    matrix_copy = new int*[n];
    for (int i = 0; i < n ; i ++)
    {
        matrix[i] = new int[n];
        matrix_copy[i] = new int[n];
        for (int j = 0 ; j < n ; j ++)
        {
            matrix[i][j] = 0;
            matrix_copy[i][j] = 0;
        }
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int u, v, w;
        cin >> u >> v;

        matrix[u-1][v-1] ++;
    }
    copy(matrix, matrix_copy);
    for (int i = 0 ; i < k-1 ; i ++){
        multiply();
    }
    int ans = matrix[s-1][t-1] % 1000003;
    cout << ans << endl;
}