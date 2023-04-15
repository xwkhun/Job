#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
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
    // 初始化距离
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 初始化队列
    queue<int> q;
    q.push(1);
    st[1] = true;  // st表明这个点是不是在队列中,true表示在队列中

    while(q.size())
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
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
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

    int t = spfa();
    if (t == -1)
        cout << "impossible" << endl;
    else 
        cout << t << endl;

    return 0;
}
