#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

struct node
{
    int value;
    bool visited = false;
    vector<int> exit_edges;
};

int main()
{
    int n, m, start;
    cin >> n >> m >> start;

    vector<node> nodes(0);
    for (int i = 0;  i <= n ; i ++)
    {
        node temp;
        temp.value = i;
        nodes.push_back(temp);
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int u, v;
        cin >> u >> v;
        nodes[u].exit_edges.push_back(v);
    }

    for (int i = 1 ; i <= n ; i ++) // reverse order of edges
    {
        reverse(nodes[i].exit_edges.begin(), nodes[i].exit_edges.end());
    }

    queue<node> q;

    q.push(nodes[start]);

    vector<bool> visited;
    for(int i = 0; i <= n  ; i++)
    {
        visited.push_back(false);
    }

    while (!q.empty())
    {
        node current = q.front();
        q.pop();

        if (visited[current.value] == false)
        {
            for (int i = 0 ; i < current.exit_edges.size(); i++)
            {
                q.push(nodes[current.exit_edges[i]]);
            }
            visited[current.value] = true;
            cout << current.value << ' ';
        }
    }

    cout << endl;

    for (int i = 1 ; i <= n ; i ++) // reverse order of edges
    {
        reverse(nodes[i].exit_edges.begin(), nodes[i].exit_edges.end());
    }

    stack<node> s;

    s.push(nodes[start]);

    vector<bool> visited(n+1, false);

    while (!s.empty())
    {
        node current = s.top();
        s.pop();

        if (visited[current.value] == false)
        {
            for (int i = 0 ; i < current.exit_edges.size(); i++)
            {
                s.push(nodes[current.exit_edges[i]]);
            }
            visited[current.value] = true;
            cout << current.value << ' ';
        }
    }
    

}