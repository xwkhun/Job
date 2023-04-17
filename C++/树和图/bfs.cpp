#include <iostream>
#include <cstring>
using namespace std;

/*
题目：

给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。
最初，有一个人位于左上角(1,1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角(n,m)处，至少需要移动多少次。
数据保证(1,1)处和(n,m)处的数字为0，且一定至少存在一条通路。

输入格式
第一行包含两个整数n和m。
接下来n行，每行包含m个整数 (0或1)，表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1 <n,m < 100
输入样例:
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出样例:
8

*/



const int N = 100;
 
int n, m;
int g[N][N]; // 地图
int d[N][N]; // 距离
pair<int, int> path[N][N]; // 最短路径
pair<int, int> q[N * N]; // 记录可走的点

int bfs()
{
    int hh = 0, tt = 0;  // 队头，队尾
    q[0] = {0, 0};
    memset(d, -1, sizeof d);

    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (hh <= tt)
    {
        auto t = q[hh++]; // 取出队头

        // 当前位置往四个方向扩展
        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i]; // 扩展一步
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) // 判断是否可走
            {
                d[x][y] = d[t.first][t.second] + 1;  // 可以走，则记录走到（x, y）位置时的距离 = 上一点的距离 + 1
                path[x][y] = t; // 记录 x, y 是从哪一点走过来的
                q[++tt] = {x, y};  // 添加所有可走位置
            }
        }
    }
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << ' ' << y << endl;
        auto t = path[x][y];
        x = t.first, y = t.second;
    }


    return d[n - 1][m - 1];
}


int main()
{
    cin >> n >> m;

    // 读取地图
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++)
            cin >> g[i][j];

    // 广搜
    cout << bfs() << endl;

    return 0;
}