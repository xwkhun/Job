#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;
int h[N], e[M], ne[M], idx;
int match[N];
int st[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int u)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])  // j之前没有被当前点匹配过
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);

    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);  // 注意这里添加边的顺序，从u到v的边， 因为后面只需要看u的其他可匹配的点，而不需要看v连接了多少条边
    }

    int res = 0;  // 当前匹配的数量
    for (int i = 1; i <= n1; i ++ )
    {
        memset(st, false, sizeof st); // 先把i当前所有考虑匹配的情况清空
        if (find(i))
            res++;
    }

    cout << res << endl;

    return 0;
}