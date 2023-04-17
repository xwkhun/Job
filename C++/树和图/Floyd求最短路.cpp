#include <iostream>

using namespace std;

const int N = 210, INF = 1e9;

int d[N][N];
int n, m, q;

void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}


int main()
{
    
    cin >> n >> m >> q;

    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < n; j ++ )
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        d[x][y] = min(d[x][y], z);  // 重边时保留最短的边
    }

    floyd();

    while(q --)
    {
        int a, b;
        cin >> a >> b;
        cout << d[a][b] << endl;
    }
    
    return 0;
}