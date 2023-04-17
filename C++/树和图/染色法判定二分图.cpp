#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 200010;
int h[N], e[M], ne[M], idx;
int color[N];  // 染色数组，0表示当前下标的点没有被染过颜色

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;  // 记录当前点的颜色

    // 从前往后遍历当前的的所有邻接点
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        // 判断是否染过颜色， 没染过则染
        if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        // 染过则判断颜色是否矛盾
        else if (color[j] == c)
            return false;
    }

    return true;
}

int main()
{
    memset(h, -1, sizeof h);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    // 设置标志，表示当前染色是否冲突， true表示无，false表示有 
    bool flag = true;  
    // 遍历每个点
    for (int i = 1; i <= n; i ++ )
        if (!color[i]) // 看看i点是否被染过颜色
        {
            if (!dfs(i, 1)) // 存在矛盾，染色失败
            {
                flag = false;
                break;
            }
        }

    if (flag)
        puts("Yes");
    else
        puts("No");
    return 0;
}
