#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool isEmpty(int** graph, int size)
{
    for (int i = 0 ; i < size ; i ++)
    {
        for (int j = 0 ; j < size ; j ++)
        {
            if (graph[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool isMax(int** graph, int size)
{
    for (int i = 0 ; i < size ; i ++)
    {
        for (int j = 0 ; j < size ; j ++)
        {
            if (i!=j && graph[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void printgraph(int** graph, int size)
{
    for (int i = 0 ; i < size ; i ++)
    {
        for (int j = 0 ; j < size ; j ++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

int solve(int** graph, int size)
{
    if (isEmpty(graph, size))
    {
        return 1;
    }

    if (isMax(graph, size))
    {
        return size;
    }

    // cout << "--------------------------" << endl;
    // cout << size << endl;
    int** graph1;
    graph1 = new int*[size];
    for (int i = 0 ; i < size ; i ++)
    {
        graph1[i] = new int[size];
        for (int j = 0 ; j < size ; j ++)
        {
            graph1[i][j] = graph[i][j];
        }
    }

    int I, J;
    bool edge_added = false;
    for (int i = 0 ; i < size ; i ++)
    {
        for (int j = 0 ; j < size ; j ++)
        {
            if (i != j && graph1[i][j] == 0 && !edge_added)
            {
                I = i; J = j;
                edge_added = true;
            }
        }
    }
    graph1[I][J] = 1;
    graph1[J][I] = 1;

    int** graph2_unshrinked;
    graph2_unshrinked = new int*[size];
    for (int i = 0 ; i < size ; i ++)
    {
        graph2_unshrinked[i] = new int[size];
        for (int j = 0 ; j < size ; j ++)
        {
            graph2_unshrinked[i][j] = graph[i][j];
        }
    }
    // merge i and j into i row

    for (int x = 0 ; x < size ; x++)
    {
        graph2_unshrinked[I][x] = graph2_unshrinked[I][x] || graph2_unshrinked[J][x];
    }

    // merge i and j into i column
    for (int x = 0 ; x < size ; x++)
    {
        graph2_unshrinked[x][I] = graph2_unshrinked[x][I] || graph2_unshrinked[x][J];
    }

    // remove row and col j

    int** graph2;
    graph2 = new int*[size-1];
    int ii = 0;
    for (int i = 0 ; i < size-1 ; i ++)
    {
        graph2[i] = new int[size-1];
        if (i == J)
        {
            ii++;
        }
        int jj = 0;
        for (int j = 0 ; j < size-1 ; j ++)
        {
            if(j == J) 
            {
                jj++;
            }
            graph2[i][j] = graph2_unshrinked[ii][jj];
            jj++;
        }
        ii++;
    }


    // printgraph(graph1, size);
    // printgraph(graph2, size-1);

    return min(solve(graph1, size), solve(graph2, size-1));
}

int main()
{
    cin >> n >> m ;

    int**grid;

    grid = new int*[n];
    for (int i = 0 ; i < n ; i ++)
    {
        grid[i] = new int[n];
        for (int j = 0 ; j < n ; j ++)
        {
            grid[i][j] = 0;
        }
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int a, b;
        cin >> a >> b;
        grid[a-1][b-1] = 1;
        grid[b-1][a-1] = 1;
    }

    // for (int i = 0 ; i < n ; i ++)
    // {
    //     for (int j = 0 ; j < n ; j ++)
    //     {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    cout << solve(grid, n) << endl;
}