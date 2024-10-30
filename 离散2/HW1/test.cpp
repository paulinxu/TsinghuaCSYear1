#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj; // Adjacency list for graph

// BFS algorithm
void bfs(int s) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        
        // Process neighbors in reverse order to comply with edge ID requirement
        for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    cout << "\n";
}

// DFS algorithm
void dfsUtil(int s, vector<bool>& visited) {
    visited[s] = true;
    cout << s << " ";
    
    // Process neighbors in reverse order to comply with edge ID requirement
    for (auto it = adj[s].rbegin(); it != adj[s].rend(); ++it) {
        if (!visited[*it]) {
            dfsUtil(*it, visited);
        }
    }
}

void dfs(int s) {
    vector<bool> visited(adj.size(), false);
    dfsUtil(s, visited);
    cout << "\n";
}

int main() {
    int n, m, s;
    cin >> n >> m >> s; // Read number of nodes, edges, and starting node
    adj.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge to adjacency list
    }

    // Sort adjacency lists to ensure that lower-numbered edges are processed first
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    bfs(s); // Perform BFS
    dfs(s); // Perform DFS

    return 0;
}