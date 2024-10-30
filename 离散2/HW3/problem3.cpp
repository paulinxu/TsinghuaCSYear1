#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <climits>


using namespace std;

const int INF = 0x3fffffff;
const int MAXN = 40;

int inline min(int a, int b) { return a < b ? a : b; }

//
// 记录结点标号（结点编号从 1 开始）
// direction[u] = 1 表示标号为正，-1 表示标号为负，0 表示未标号
// from[u] 表示结点 u 是因为哪个结点才得到标号的
// delta[u] 表示从源到 u 的增流路径上最大的可增流量
//
int direction[MAXN + 1], from[MAXN + 1], delta[MAXN + 1];

int n, m, s, t;

class Graph {
public:
    // TODO: 选择适合本题的图数据结构并实现
    
    int ** flows;
    int ** capacities;

    void setGraph()
    {
        flows = new int*[MAXN+1];
        capacities = new int*[MAXN+1];
        for (int i = 0 ; i < MAXN + 1 ; i ++)
        {
            flows[i] = new int[MAXN+1];
            capacities[i] = new int[MAXN+1];
            for (int j = 0 ; j <= MAXN + 1 ; j ++)
            {
                flows[i][j] = 0;
                capacities[i][j] = -1;
            }
        }
    };

    // 返回指定边的流量
    int Flow(int u, int v) { return flows[u][v]; }

    // 返回指定边的容量
    int Capacity(int u, int v) { return capacities[u][v]; }

    // 添加一条从 u 到 v 的单向边，容量为 c，流量为 f
    void AddEdge(int u, int v, int c, int f) {
        flows[u][v] = f;
        capacities[u][v] = c;
    }

} G;

//
// 适用于 Ford-Fulkerson 算法的标号过程，基于深度优先搜索给所有结点标号
//
void label_dfs(int u) {

    if (u == t)
    {
        return;
    }

    for (int v = 1 ; v <= MAXN ; v++/* TODO: 枚举每一个 v 满足 (u, v) 在图中 */) {
        // 如果 v 访问过，跳过该结点
        if (G.capacities[u][v] == -1) {continue;}
        if (direction[v] != 0)
            continue;

        int c = G.Capacity(u, v);
        int f = G.Flow(u, v);
        if ( f < c /* TODO: 判断是否需要更新 v 的标号 */) {
            // TODO: 更新标号
            from[v] = u;
            direction[v] = 1;
            delta[v] = min(delta[u], c - f);
            label_dfs(v); // 从 v 出发，搜索邻接的未标号结点
        }
    }
    for (int v = 1 ; v <= MAXN ; v++ /* TODO: 枚举每一个 v 满足 (v, u) 在图中 */) {
        // TODO: 仿照以上代码补全反向标号过程
        if (G.capacities[v][u] == -1) {continue;}
        if (direction[v] != 0)
            continue;
        int c = G.Capacity(v, u);
        int f = G.Flow(v, u);
        if ( f > 0 /* TODO: 判断是否需要更新 v 的标号 */) {
            // TODO: 更新标号
            from[v] = u;
            direction[v] = -1;
            delta[v] = min(delta[u], f);

            label_dfs(v); // 从 v 出发，搜索邻接的未标号结点
        }
    }
}

//
// 适用于 Edmonds-Karp 算法的标号过程，基于广度优先搜索给所有结点标号
//
void label_bfs() {
    static int q[MAXN + 1];
    int hd = 0, tl = 0;
    q[tl++] = s; // 第一个搜索源点
    while (hd < tl) {
        int u = q[hd++]; // 按入队顺序取出未标号结点
        for (int v = 1 ; v <= MAXN ; v++) {
            if (G.capacities[u][v] == -1) {continue;}
            if (direction[v] != 0)
                continue;
            int c = G.Capacity(u, v);
            int f = G.Flow(u, v);
            if (f < c) {
                from[v] = u;
                direction[v] = 1;
                delta[v] = min(delta[u], c - f);
                q[tl++] = v; // 从 v 出发，搜索邻接的未标号结点
            }
        }
        for (int v = 1 ; v <= MAXN ; v++) {
            if (G.capacities[v][u] == -1) {continue;}
            if (direction[v] != 0)
                continue;
            int c = G.Capacity(v, u);
            int f = G.Flow(v, u);
            if (f > 0) {
                from[v] = u;
                direction[v] = -1;
                delta[v] = min(delta[u], f);
                q[tl++] = v; // 从 v 出发，搜索邻接的未标号结点
            }
        }
    }
}

//
// Ford-Fulkerson 及 Edmonds-Karp 算法中的标号过程。
//
bool label() {
    // TODO: 初始化标号数组
    delta[s] = INF;
    // 深度/广度优先搜索的调用入口，基于 bfs 或 dfs 实现均可
    // label_dfs(s);
    // OR
    label_bfs();
    // 通过汇点是否被标号判断允许流是否存在
    return direction[t] != 0;
}

void printPath() {
    int pathLength = 0;
    static int Path[MAXN + 1];
    // 根据记录的 from 数组，从汇点倒推出增流路径
    for (int v = t; v != s; v = from[v]) {
        Path[pathLength++] = v;
    }
    // TODO: 按照题目要求向标准输出中打印结果
    cout << pathLength+1 << ' ' << delta[t] << endl;
    cout << s << ' ';
    for (int i = pathLength-1 ; i >= 0 ; i --)
    {
        cout << Path[i] << ' ';
    }

}

void init() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    G.setGraph();
    for (int i = 0; i < m; i++) {
        int u, v, c, f;
        scanf("%d%d%d%d", &u, &v, &c, &f);
        G.AddEdge(u, v, c, f);
    }
    
}

int main() {
    init();
    if (label()) {
        printPath();
    } else {
        printf("-1\n");
    }
}