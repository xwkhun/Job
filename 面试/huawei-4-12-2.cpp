#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;

/*
主办方设计了一个获取食物的游戏。游戏的地图由N个方格组成，每个方格上至多2个传送门，通过传送门可将参与者传送至指定的其它方格。同时，每个方格上标注了三个数字: (1) 第一个数字id:代表方格的编号，从0到N-1，每个方格各不相同; (2)第二个数字parent-id:代表从编号为parent-id的方格可以通过传送门传送到当前方格(-1则表示没有任何方格可以通过传送门传送到此方格，这样的方格在地图中有且仅有一个); (3)第三个数字value: 取值在[-100，100]的整数值，正整数代表参与者得到相队取值单位的食物，负整数代表失去相应数值单位的食物(参与者可能存在临时持有食物为负数的情况)，0则代表无变化。此外，地图设计时保证了参与者不可能到达相同的方格两次，并且至少有一个方格的value是正整数。

游戏开始后，参与者任意选择一个方格作为出发点，当遇到下列情况之一退出游戏: (1)参与者当前所处的方格无传送门: (2) 参与者在任意方格上丰动宣布退出游戏 请计算参与者退出游戏后，最多可以获得多少单位的食物 

解答要求 
时间限制: C/C++ 1300ms.其他语言:2600ms内存限制: C/C++256MB其他语言:512MB 第一行:方块个数N (N<10000)

样例1输入：
7
0 1 8
1 -1 -2
2 1 9
4 0 -2
5 4 3
3 0 -3
6 2 -3

输出：
9

解释：
参与者从方格0出发，通过传送门到达方格4，再通过传送门到达方格5。一共获得8+(-2) +3=9个单位食物，得到食物展多: 或者参与者在游戏开始时处于方格2，直接主动宣布退出游戏，也可以获得9个单位食物。

样例2输入：
3
0 -1 3
1 0 1
2 0 2

输出：
5

解释:
参与者从方格0出发，通过传送门到达方格2，一共可以获得3+2=5个单位食物，此时得到食物最多。
*/

// 方法一：yxc 深度优先遍历DFS模板

// int q[N], benefit[N];
// int h[N], e[N], ne[N], idx;
// bool st[N];

// void add(int a, int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }

// int dfs(int u)
// {
//     st[u] = true;  // 标记已遍历过
//     q[u] = benefit[u]; // 节点u的初始食物

//     // 遍历从u点开始的所有可行路线
//     for (int i = h[u]; i != -1; i = ne[i])
//     {
//         int j = e[i];
//         if (!st[j])   // 该点没有被遍历过 
//             q[u] = max(q[u], benefit[u] + dfs(j));  // 更新以u为起始点的路线所能获得的最大食物
//         // cout << "u: " << u << ' ' << q[u] << ' ';
//     }

//     // printf("\n第%d个点, res: %d\n", u, q[u]);
//     return q[u];
// }


// int main()
// {
//     // 初始化n个单链表
//     memset(h, -1, sizeof h);

//     int n;
//     cin >> n;
//     // 添加方格之间的边
//     for (int i = 0; i < n; i ++ )
//     {
//         int a, b, c;
//         cin >> a >> b >> c;

//         // 去除-1的情况
//         if (b != -1)
//             add(b, a);  
//         benefit[a] = c;  // 初始化每个方格能获得的食物
//     }

//     int ans = 0;
//     for (int i = 0; i < n; i ++ )
//     {
//         ans = max(ans, dfs(i));
//         cout << endl;
//     }

//     cout << ans << endl;

//     return 0;
// }


// 方法二：树形DP
#include <vector>
#include <algorithm>
vector<vector<int>> p;
vector<int> ans;  // 答案

int dfs(int n)
{
    if (ans[n] != INT_MIN)
        return ans[n];
    if (p[n][0] == -1) 
        return p[n][1];
    ans[n] = max(p[n][1], p[n][1] + dfs(p[n][0]));
    return ans[n];
}


int main()
{
    int n;
    cin >> n;

    // 初始化p, 调用拷贝构造函数
    p = vector<vector<int>>(n, vector<int>(2));


    // 输入每个方格的父节点和初始食物
    for (int i = 0; i < n; i ++ )
    {
        int id, pid, val;
        cin >> id >> pid >> val;
        p[id][0] = pid;
        p[id][1] = val;
    }

    // 初始化ans
    ans = vector<int>(n, INT_MIN);
    for (int i = 0; i < n; i ++ )
    {
        dfs(i);
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}