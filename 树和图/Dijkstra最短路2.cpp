#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 10010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int st[N];


// 堆优化版Dijkstra算法

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int heap_dijkstra(int n)
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;   // 1号点距离为0；

    // 初始化一个升序优先队列：小根堆，用于存放所有未找到最短距离的点 <距离, id>
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        // 取出堆顶, 由于是小根堆，每次新加入一个点都会自动排序，堆顶总是最小值，因此堆顶是未找到最短距离的点列表中的最小值
        // 取出这个点作为已求出 最小路径的点
        auto t = heap.top();
        heap.pop();

        int id = t.second, distance = t.first;
        if (st[id]) continue;  // 如果这个点已经遍历过，那么跳过

        for (int i = h[id]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];    // j点经过t点到达1号点的距离更短，更新
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
    int n, m;
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << heap_dijkstra(n) << endl;
    return 0;
}
