#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 10;
int p[N];
bool st[N];

// 全排列问题
void dfs(int n, int u)
{
    // n == u 说明已经遍历到最后一层
    // 输出结果
    if (n == u) 
    {
        for (int i = 0; i < n; i ++ )
            cout << p[i] << ' ';
        cout << endl;
        return; 
    }

    // u < n 的时候，枚举没有被使用过的数
    for (int i = 1; i <= n; i ++ )
    {   
        // 当前这个数没有被用过
        if (!st[i])
        {
            p[u] = i;
            st[i] = true;
            dfs(n, u + 1);
            st[i] = false;  // 为回溯做准备，恢复现场
        }
    }
}


// 回溯算法模板
/*
void backtracking(参数)
{
    if (终止条件)
    {
        存放结果
        return;
    }

    for (选择：本层集合中元素 (树中节点孩子的数量就是集合的大小))
    {
        处理节点；
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

*/


// N皇后问题
vector<vector<string>> result;
bool isValid(int row, int col, vector<string> &chessboard, int n);
// n 为输入的棋盘大小
// row 是当前递归到棋牌的第几行了

void backtracking(int n, int row, vector<string>& chessboard)
{
    if (row == n)
    {
        result.push_back(chessboard);
        return;
    }

    for (int col = 0; col < n; col ++ )
    {
        // 检验是否满足条件
        if (isValid(row, col, chessboard, n))
        {
            chessboard[row][col] = 'Q';  // 放置皇后
            backtracking(n, row + 1, chessboard); // 递归
            chessboard[row][col] = '.'; // 回溯，撤销皇后
        }
    }
}


bool isValid(int row, int col, vector<string>& chessboard, int n)
{
    int count = 0;
    // 检查列
    for (int i = 0; i < row; i ++ )
    {
        if (chessboard[i][col] == 'Q')
            return false;
    }

    // 检查45°角是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')
            return false;
    }

    // 检查135°角是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (chessboard[i][j] == 'Q')
            return false;
    }

    return true;
}


int main()
{
    int n;
    cin >> n;

    // 全排列问题
    // dfs(n, 0);

    // N皇后问题
    vector<string> chessboard(n, string(n, '.'));
    backtracking(n, 0, chessboard);

    for (auto res: result)
    {
        for (auto r: res)
        {
            cout << r << ' ';
            cout << endl;
        }

        cout << endl;
    }


    return 0;
}