#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n; 
int **grid;
// int strength;
// int **strength_grid;


int getcost(const vector<int>& currentPath) 
{
    int sum = 0;
    for (int i = 0; i < currentPath.size() - 1; i++) 
    {
        sum += grid[currentPath[i]][currentPath[i+1]];
    }
    
    return sum;
}

// int getstringthcost(const vector<int>& currentPath) 
// {
//     int sum = 0;
//     for (int i = 0; i < currentPath.size() - 1; i++) 
//     {
//         sum += strength_grid[currentPath[i]][currentPath[i+1]];
//     }
    
//     return sum;
// }

string getPathString(const vector<int>& currentPath)
{
    string text = "";
    for(int i = 0; i < n ; i ++)
    {
        text += char('0'+currentPath[i]);
    }
    return text;
}

void dfs(int current, vector<bool>& visited, vector<int>& currentPath, int& mincost, int n, vector<int>& minimumPath) 
{
    if (currentPath.size() == n) 
    {
        
        // if (getstringthcost(currentPath) > strength)
        // {
        //     return;
        // }

        int currentcost = getcost(currentPath);
        if (currentcost == mincost)
        {
            string a = getPathString(minimumPath);
            string b = getPathString(currentPath);
            if (b < a)
            {
                mincost = currentcost;
                minimumPath.clear();
                minimumPath = currentPath;
            }
        }
        else if (currentcost < mincost)
        {
            mincost = currentcost;
            minimumPath.clear();
            minimumPath = currentPath;
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) 
        {
            visited[i] = true;
            currentPath.push_back(i);

            dfs(i, visited, currentPath, mincost, n, minimumPath);

            visited[i] = false;
            currentPath.pop_back();
        }
    }
}

int main() 
{
    // cin >> n >> strength;
    cin >> n;
    grid = new int*[n];
    for (int i = 0 ; i < n ; i ++)
    {
        grid[i] = new int[n];
        for (int j = 0 ; j < n ; j++)
        {
            cin >> grid[i][j];
        }
    }

    // strength_grid = new int*[n];
    // for (int i = 0 ; i < n ; i ++)
    // {
    //     strength_grid[i] = new int[n];
    //     for (int j = 0 ; j < n ; j++)
    //     {
    //         cin >> strength_grid[i][j];
    //     }
    // }

    int mincost = 2147483647;
    vector<int> minimumPath;
    vector<int> currentPath;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) 
    {
        currentPath.push_back(i);
        visited[i] = true;

        dfs(i, visited, currentPath, mincost, n, minimumPath);

        currentPath.pop_back();
        visited[i] = false;
    }

    cout << mincost << endl;
    for (int i = 0 ; i < minimumPath.size() ; i ++)
    {
        cout << minimumPath[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}