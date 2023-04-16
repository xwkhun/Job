#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n, 0);

    for (int i = 0; i < n; i ++ )
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // for (int i = 0; i < n; i ++ )
    // {
    //     cout << nums[i];
    // }

    double res = 0, tot = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k - 1)
            res += nums[i];
        else
        {
            tot += nums[i];
            cnt += 1;
        }
    }
 
    res += (double) tot / cnt;
    printf("%.10f\n", res);

    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #include <cmath>
// using namespace std;

// const int MAXN = 1e5 + 5;
// double a[MAXN], sum[MAXN];
// double dp[MAXN][105];

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         sum[i] = sum[i - 1] + a[i];
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= k; j++)
//         {
//             dp[i][j] = 1e9;  // 初始化为一个很大的数
//             if (j == 1)
//             {
//                 dp[i][j] = sum[i] / i;
//             }
//             else
//             {
//                 for (int p = j - 1; p < i; p++)
//                 {
//                     dp[i][j] = min(dp[i][j], dp[p][j - 1] + (sum[i] - sum[p]) / (i - p));
//                 }
//             }
//         }
//     }
//     printf("%.6f\n", dp[n][k]);
//     return 0;
// }
