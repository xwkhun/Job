#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
题目：
给定一颗树，树中包含n个结点编号(1~n) 和 n-1 条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
重心定义:重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数n，表示树的结点数。
接下来n-1行，每行包含两个整数a和b，表示点a和点b之前存在一条边。

输出格式
输出一个整数m，表示重心的所有的子树中最大的子树的结点数目。
数据范围
1≤n≤10^5

输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

输出样例
4
*/


// 无向图，因此两个结点之间要建两条边 
int n;

const int N = 100010, M = N * 2;

int h[N], e[M], ne[M], idx;  // h是N个头结点
bool st[N]; // 记录点是否被遍历

// 记录全局答案
int ans = N;

// 插入结点
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];  // 当前点的ne指向h指向的值
    h[a] = idx++; // h指向当前点，idx往后移动一位
}

// 计算以u为根的子树中点的数量
int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;  // res记录每一个连通块的大小的最大值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i]; // 取出当前点的下一个点

        // 该点没有被遍历过，那么继续往下搜，直到搜到该链表结束
        if (!st[j])
        {
            int s = dfs(j); // 当前子树的大小
            res = max(res, s);  // 比较当前子树节点数和当前连通块最大值哪个更大，更新
            sum += s;  // sum是从当前节点往下搜索到的节点的累加
        }   
    }

    // cout << sum << endl; 
    // u的子树遍历完，更新最大的连通块
    res = max(res, n - sum);
    // cout << res << endl;
    // 更新最小的最大连通块
    ans = min(ans, res);

    return sum;
}


int main()
{
    // 初始化邻接表的头指针
    memset(h, -1, sizeof h);

    // 输入节点数
    cin >> n;

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;  // 输入点a和点b
        add(a, b), add(b, a);  // 添加两条边
    }

    for (int i = 1; i <= n; i ++ )
    {
        cout << i << " 点： ";
        for (int j = h[i]; j != -1; j = ne[j])
        {
            cout << e[j] << ' ';
        }

        cout << endl;
    }

    // 从任意一个节点开始搜索都可以
    dfs(1);

    cout << ans << endl;

    return 0;
}