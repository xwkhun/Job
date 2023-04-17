#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;
int p[N];

struct edge
{
    int u, v, w;

    bool operator< (const edge &W) const
    {
        return w < W.w;
    }

}edges[N];  // 初始化一个结构体数组


int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    // 对边集的权重进行排序
    sort(edges, edges + m);

    // 初始化并查集的集合
    for (int i = 0; i < n; i ++ )
        p[i] = i;

    // 从小到大依次遍历每条边
    int cnt = 0;  // 最小生成树的边数
    int res = 0;  // 最小生成树中所有边权之和
    for (int i = 0; i < m; i ++ )
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;

        u = find(u), v = find(v); // 查找u和v的祖宗节点
        // 祖宗节点不同，说明不在一个集合中
        if (u != v)
        {
            p[u] = v;  // 把v加到集合中，即让u的父节点指向v
            res += w;
            cnt++;
        }
    }

    if (cnt != n - 1)  // 最小生成树的边数应该等于节点数-1
        puts("impossible");
    else
        cout << res << endl;

    return 0;
}