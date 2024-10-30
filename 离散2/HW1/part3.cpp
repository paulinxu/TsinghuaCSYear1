#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;

void DFS(int s, vector<bool>& visited, vector<vector<int>>& edges) {
    visited[s] = true;
    cout << s << " ";
    
    for (auto it = edges[s].rbegin() ; it < edges[s].rend() ; it++) 
    {
        if (visited[*it] == false) 
        {
            DFS(*it, visited, edges);
        }
    }
}

int main()
{
    cin >> n >> m >> s;

    vector<vector<int>> edgesBFS(n+1);
    vector<vector<int>> edgesDFS(n+1);

    vector<bool> visitedBFS(n+1, false);

    queue<int> q;

    for (int i = 0 ; i < m ; i++) 
    {
        int u , v;
        cin >> u >> v;
        edgesBFS[u].push_back(v);
        edgesDFS[u].push_back(v);
    }

    // BFS

    q.push(s);
    visitedBFS[s] = true;

    while (!q.empty()) 
    {
        int current = q.front(); 
        q.pop();
        cout << current << " ";
        
        for (auto it = edgesBFS[current].rbegin() ; it < edgesBFS[current].rend() ; it++) 
        {
            if (!visitedBFS[*it]) 
            {
                visitedBFS[*it] = true;
                q.push(*it);
            }
        }

    }
    cout << endl;

    // DFS 

    vector<bool> visitedDFS(n+1, false);
    DFS(s, visitedDFS, edgesDFS);

}