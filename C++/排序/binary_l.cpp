#include <iostream>

using namespace std;

const int N = 100010;
int q[N];


int main()
{
    // int n, m; // 输入数组长度和询问个数
    // cin >> n >> m;
    // for (int i = 0; i < n; i ++ )
    // {
    //     cin >> q[i];
    // }

    // for (int i = 0; i < m; i ++ )
    // {
    //     int k;  // 询问元素
    //     cin >> k;

    //     int l = 0, r = n - 1;
    //     while(l < r)
    //     {
    //         int mid = (l + r) >> 1;
    //         if (q[mid] >= k) r = mid;
    //         else l = mid + 1;
    //     }

    //     if (q[l] != k)
    //         cout << "-1 -1" << endl;
        
    //     else
    //     {
    //         cout << l << " ";
    //         l = 0, r = n - 1;
    //         while(l < r)
    //         {
    //             int mid = (l + r + 1) >> 1;
    //             if (q[mid] <= k)
    //                 l = mid;
    //             else
    //                 r = mid - 1;
    //         }
    //         cout << l << endl;
    //     }
    // }


    // 浮点数二分 例子：开根号
    // 无需处理边界问题
    double k;
    cin >> k;
    double l = 0;
    double r;
    if (k >= 1) r = k;
    else if(k >= 0) r = 1.0;

    while(r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid >= k)
            r = mid;
        else
            l = mid;
    }

    cout << l << endl;
}