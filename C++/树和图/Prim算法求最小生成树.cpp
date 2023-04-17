#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
int st[N];

int prim(int n)
{
    // 初始化距离数组为无穷大
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;  // 表示还没找到任何一点
        // 找到集合外距离集合最小的点
        for (int j = 1; j <= n; j ++ )
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;   // j点未被遍历过， t点是最初点或者t到集合的距离大于j到集合的距离，那么更新t=j
        }

        if (i && dist[t] == INF) return INF; // 如果不是第一点，但到集合的最小距离是INF，说明该点与集合不连通，那么该图不存在最小生成树
        if (i) res += dist[t];   // 不是第一点，更新最小生成树边权，注意这句要在更新其他点到集合的距离之前，因为如果t点有自环，则会把dist[j]变小，而最小生成树不能有自环

        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }
    return res;
}


int main()
{
    int n, m;
    cin >> n >> m;

    // 注意将邻接矩阵初始为无穷大
    memset(g, 0x3f, sizeof g);

    // 读入所有边
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }

    int t = prim(n);

    if (t == INF)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}