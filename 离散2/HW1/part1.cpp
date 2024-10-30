#include <iostream>
#include <vector>

using namespace std;

int n, m;
int **matrix;

struct edge
{
    int u, v, w, next;
};

vector<edge> edges(0);

void printm()
{
    for (int i = 0; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;

    matrix = new int*[n];
    for (int i = 0; i < n ; i ++)
    {
        matrix[i] = new int[n];
        for (int j = 0 ; j < n ; j ++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (matrix[u-1][v-1] == 0)
        {
            matrix[u-1][v-1] = w;
        }
        else{
            matrix[u-1][v-1] = -1;
        }

        edge temp;
        temp.u = u; temp.v = v; temp.w = w; temp.next = 0;
        edges.push_back(temp);
    }
    printm();
    // for (int i = 0 ; i < m ; i ++)
    // {
    //     cout << edges[i].u << edges[i].v << edges[i].w << edges[i].next << endl;
    // }

    int *starting_indexes;
    starting_indexes = new int[n];

    for (int i = 0; i < n ; i++)
    {
        starting_indexes[i] = 0;
    }

    for (int v = 0; v < n ; v ++)
    {
        for (int i = m-1 ; i >=0 ; i --)
        {
            if(edges[i].u == v+1)
            {
                starting_indexes[v] = i+1;
                break;
            }
        }
    }

    for (int i = 0; i < n ; i++)
    {
        cout << starting_indexes[i] << endl;
    }
    for (int v = 1 ; v <= n ; v ++)
    {
        int prev = starting_indexes[v-1]-1;
        int current = prev-1;
        
        while (current >= 0)
        {
            if(edges[current].u == v)
            {
                edges[prev].next = current+1;
                prev = current;
            }
            current--;
        }
    }
    for (int i = 0; i < m ; i++)
    {
        cout << edges[i].v << ' ' << edges[i].w << ' ' << edges[i].next << endl;
    }


}