#include <iostream>
#include <cstring>
using namespace std;

/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。所有边的长度都是1，点的编号为1~n。
请你求出1号点到n号点的最短距离，如果从1号点无法走到n号点，输出-1。

输入格式
第一行包含两个整数n和m。
接下来m行，每行包含两个整数a和b，表示存在一条从a走到b的长度为1的边。

输出格式
输出一个整数，表示1号点到n号点的最短距离。
数据范围
1 ≤ n, m ≤ 10^5

输入样例:
4 5
l 2
2 3
3 4
1 3
1 4

输出样例:
1

*/

const int N = 100010;

int d[N], q[N];  // d 是从初始点到n的最短距离，q是边队列
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


int bfs(int n)
{
    int hh = 0, tt = 0; // 初始化队头和队尾
    q[0] = 1; // 路径第一个元素是起点1

    memset(d, -1, sizeof d); // 距离初始化为-1，表示没有被遍历过
    d[1] = 0;

    while (hh <= tt)
    {
        int t = q[hh++]; // 取出队头
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1) // j点没有被扩展过
            {
                d[j] = d[t] + 1;  // 距离累加
                q[++tt] = j;  // 当前点加入队列中
            }
        }
    }

    return d[n];
}

int main()
{
    // 初始化n个单链表
    memset(h, -1, sizeof h);

    int n, m;
    // 输入n个点m条边
    cin >> n >> m;

    // 输入所有边
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs(n) << endl;

    return 0;
}