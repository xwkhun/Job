// 有向无环图一定有拓扑序列，也叫拓扑图
// 入度和出度， 入度为0的点排在最前面，入队

/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1。
若一个由图中所有点构成的序列A满足:对于图中的每条边(x, y)，x在A中都出现在y之前，则称A是该图的一个拓扑序列。

输入格式
第—行包含两个整数n和m
接下来m行，每行包含两个整数x和y，表示点x和点y之间存在一条有向边(x, y)。

输出格式
共—行，如果存在拓扑序列，则输出拓扑序列。否则输出-1。

数据范围
1 ≤n, m ≤ 10^5

输入样例:
3 3
1 2
1 3
2 3

输出样例：
1 2 3

*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int q[N], d[N];
int h[N], e[N], ne[N], idx;

int n, m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


bool topsort()
{
    int hh = 0, tt = -1;

    // 由于入度为0的点没有先后顺序，因此当入度为0的点大于1则问题应该是多解的，这里只按节点顺序进行排列
    for (int i = 1; i <= n; i ++ )
    {   
        // 入度为0的点插入q中
        if (!d[i])
            q[++tt] = i;
    }

    while (hh <= tt)
    {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;   // 入度减1
            if (d[j] == 0) q[++tt] = j;  // 当入度减为0，说明这个点一定在入度不为0的点之前，则该点可以入队
        }
    }

    return tt == n - 1;  // 如果队尾元素刚好等于所有节点数，说明该图有拓扑序, q即为排好序的数组，否则无
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (topsort())
    {
        for (int i = 0; i < n; i ++ )
            cout << q[i] << " ";
        cout << endl;
    }

    else
        puts("-1");

    return 0;
}