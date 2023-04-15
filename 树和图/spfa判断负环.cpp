#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int cnt[N];
int st[N];


int n, m;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa()
{
    // // 初始化距离
    // memset(dist, 0x3f, sizeof dist);
    // dist[1] = 0;

    // 初始化队列，由于题目是判断是否存在负环，并不是判断从1号点到n号点是否存在负环，负环可能存在于其他点到另一个点的路径上，因此初始时要将所有点都添加到队列中
    queue<int> q;

    for (int i = 1; i <= n; i ++ )
    {
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main()
{
    // 初始化邻接表
    memset(h, -1, sizeof h);

    cin >> n >> m;
    // 输入边信息
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    // int t = spfa();
    // if (t == -1)
    //     cout << "impossible" << endl;
    // else 
    //     cout << t << endl;

    if (spfa())
        puts("Yes");
    else
        puts("No");

    return 0;
}
