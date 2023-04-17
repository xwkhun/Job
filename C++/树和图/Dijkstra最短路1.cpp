#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

// 朴素dijkstra算法

int dijkstra()
{
    // 先把所有点的距离初始化成正无穷
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;  // 1号点的距离是0

    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        // 从所有未求出最短距离的点中找出距离最小的点
        for (int j = 1; j <= n; j ++ )
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        // 表示t号点已经求得最短距离
        st[t] = true;

        // i = 0时，先把所有dist更新为邻接矩阵中与1号点有边相连的边距离，此时除1号点外，其他所有点都未求出最短距离
        // i != 0 时，由于t号点已经求得最短距离，此时可通过t号点作为从1号点到 j号点的中转， 如果这样的距离小于原先j号点的最短距离，则更新 j号点的最短距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    // N号点的距离仍为无穷大，说明N号点到1号点没有路径
    if (dist[n] == 0x3f3f3f3f)
        return -1;

    return dist[n];
}


int main()
{   
    scanf("%d%d", &n, &m);

    // 初始化邻接矩阵为正无穷
    memset(g, 0x3f, sizeof g);
    // cout << g[1][1] << endl;

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    // 计算最短距离
    cout << dijkstra() << endl;

    return 0;
}