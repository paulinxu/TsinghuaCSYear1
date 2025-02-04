#include <cstdio>  // scanf, printf
#include <cstdlib>  // abs
#include <vector>  // std::vector
#include <algorithm>  // std::sort
#include <cmath>
#include <stack>
#include <iostream>

// =============================================================
// 数据读入部分

// n 的最大范围
const int MAX_N = 100;

// 题目中的 n
int n, q;

// 各个物流仓库的坐标（下标从 1 开始）
int X[MAX_N + 1], Y[MAX_N + 1];



// =============================================================
// 最小生成树求解部分 —— 边权值计算

// 表示边的结构体：连接 u 和 v，边权值为 cost
struct Edge {
    int u, v;
    long long cost;
};

// 计算结点 i 和结点 j 之间的边权值
// “物流道路的成本为 |X[i]-X[j]|^3 + |Y[i]-Y[j]|^3”
// 注意：使用 long long 数据类型
long long calc_cost(int i, int j) {
    // !!! TODO: 你的代码 !!!
    
    return pow(abs(X[i]-X[j]), 3) + pow(abs(Y[i]-Y[j]), 3);
}

// =============================================================
// 最小生成树求解部分 —— 回路判定

// adj[i] 表示从结点 i 出发的边
std::vector<Edge> adj[MAX_N + 1];

// 初始化一张空的图 T
void init_empty_graph() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();  // 清空结点 i 出发的边
    }
}

// 判断从 u 出发是否能到达 v（使用 DFS）
// 也可使用 BFS 进行判断（请自行编写）
bool dfs(int u, int v) {
    // !!! TODO: 你的代码 !!!
    using namespace std;
    stack<int> s;
    vector<bool> visited(n+1, false);
    s.push(u);
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        for (int ed = 0 ; ed < adj[current].size() ; ed++)
        {
            if (!visited[adj[current][ed].v])
            {
                s.push(adj[current][ed].v);
                
                if (adj[current][ed].v == v)
                {
                    return true;
                }
            } 
        }
        visited[current] = true;
    }
    return false;
}

// 判断当前图加入边 e 后是否有回路
bool has_cycle(Edge e) {
    // T+e 有回路 ↔ T 中 e 的两个端点 u 和 v 连通
    // 因此只需从 u 出发，判断是否可以到达 v
    
    // !!! TODO: 你的代码 !!!
    //
    //
    //
    return dfs(e.u, e.v);
}

// 添加边 e 到图 T 中
void add_edge(Edge e) {
    // 注意！由于是无向图，需要在两个方向均存储该边
    int u = e.u, v = e.v;
    long long cost = e.cost;
    Edge temp1 = { u, v, cost };
    Edge temp2 = { v, u, cost };
    adj[u].push_back(temp1);
    adj[v].push_back(temp2);
}

// =============================================================
// 最小生成树求解部分 —— Kruskal 算法

// 比较边的权值大小
bool cmp_edge_cost(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

// 求解最小生成树，使用 Kruskal 算法：
//   1. 将所有边（按照边权值）从小到大排序
//   2. 从一张空的图 T 开始，依次考虑排序后的各条边 e
//     a. 如果图 T+e 无回路，则 T ← T+e
//     b. 如果图 T+e 有回路，跳过这条边

std::vector<Edge> edges;

void solve(int u, int v, int c) {
    // 准备所有边

    using namespace std;

    for (vector<Edge> &x : adj)
    {
        x.clear();
    }
    
    // 1. 将所有边（按照边权值）从小到大排序
    // 排序时需要指定“比较器”，这里使用基于边权值的比较
    std::sort(edges.begin(), edges.end(), cmp_edge_cost);
    
    // 2. 从一张空的图 T 开始
    long long total_cost = 0;  // 总成本 = 0
    init_empty_graph();  // 初始化一张空的图 T
    
    // 依次考虑排序后的各条边 e
    for (Edge e : edges) {
        // a. 如果图 T+e 无回路，则 T ← T+e
        // b. 如果图 T+e 有回路，跳过这条边
        
        if (!has_cycle(e)) {  // 判断 T+e 是否无回路
            // T ← T+e
            // 总成本 += e 的成本
            // !!! TODO: 你的代码 !!!
            
            add_edge(e);
            total_cost += e.cost;
            
        }
    }
    
    // 输出答案（总成本）
    printf("%lld\n", total_cost);
}

// =============================================================
// 主函数

using namespace std;

int main() {
    cin >> n >> q;
    
    // 读取各个物流仓库的坐标 (x, y)
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &X[i], &Y[i]);
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            // !!! TODO: 你的代码 !!!
            // cout << "Added edge " << i << '-' << j << ": " << endl;
            Edge e = {i, j, calc_cost(i,j)};
            
            edges.push_back(e);  // 添加边 e
        }
    }

    solve(0, 0, 0);
    for (int i = 0 ; i < q ; i ++)
    {
        // cout << "CALLED: solve" << endl;
        int u , v , c;
        cin >> u >> v >> c;

        for (Edge &edge : edges)
        {
            if (edge.u == v && edge.v == u)
            {
                edge.cost = min(edge.cost, c);
                // cout << u << v << c << endl;
            }
        }

        solve(u, v, c);
    }
}
