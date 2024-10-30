#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int n, m; 
int **grid;

struct edge
{
    int u;
    int v;
    int w;
};

struct node
{
    int s;
    int pi;
};

vector<edge> edges;

bool lesser(node a, node b)
{
    if (a.pi < b.pi)
    {
        return true;
    }
    return false;
}

int main() 
{
    cin >> n >> m;
    grid = new int*[n];
    for (int i = 0 ; i < n ; i ++)
    {
        grid[i] = new int[n];
        for (int j = 0 ; j < n ; j++)
        {
            grid[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0 ; i < m ;  i++)
    {
        edge temp;
        int u, v, w;
        cin >> u >> v >> w;
        if (true)
        {
            
            grid[u][v] = w;
            temp.u = u;
            temp.v = v;
            temp.w = w;
            edges.push_back(temp);
            
        }
        
    }
    

    
    vector<node> S;
    vector<int> results;
    for (int i = 0 ; i < n ; i ++)
    {
        node temp;
        temp.s = i;
        temp.pi = INT_MAX;
        S.push_back(temp);
        results.push_back(INT_MAX);
    }

    for (int i = 0 ; i < edges.size() ; i ++)
    {
        if (edges[i].u == 0)
        {
            S[edges[i].v].pi = edges[i].w;
        }
    }

    S.erase(S.begin());

    while (true)
    {
        
        sort(S.begin(), S.end(), lesser);

        node j = S[0];
        results[j.s] = j.pi;

        S.erase(S.begin());


        if (S.size() == 0){break;}
        else
        {
            for (node &i : S)
            {
                if (grid[j.s][i.s] <= 10000)
                {
                    i.pi = min(i.pi, j.pi + grid[j.s][i.s]);
                }
            }
        }

        

    }

    cout << results[n-1] << endl;
    
    
    // for (int i = 0 ; i < n ; i ++)
    // {
    //     cout << results[i] << endl;
    // }
    
}