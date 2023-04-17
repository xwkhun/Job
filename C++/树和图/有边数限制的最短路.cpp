#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge
{
    int a, b, w;
} edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 最多只能经过k条边，迭代k次不会超过k条边
    for (int i = 0; i < k; i ++ )
    {
        // dist是上次迭代的结果，把dist备份一下，防止当前点更新后，把其他点给更新了。
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++ )
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    // 由于存在负权边，一个距离1号点是无穷的点可能被另一个距离1号点是无穷的点更新了，这两点之间存在有效距离，使这个点距离1号点的距离不再是无穷
    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int t = bellman_ford();

    if (t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}