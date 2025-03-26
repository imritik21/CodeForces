#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15; // Use a large number as infinity

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> matrix(n + 1, vector<ll>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        matrix[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        matrix[x][y] = min(matrix[x][y], w);
        matrix[y][x] = min(matrix[x][y], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][k] != INF && matrix[k][j] != INF)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == INF)
                matrix[i][j] = -1;
            // cout << -1 << " ";
            // else
            // cout << matrix[i][j] << " ";
        }
        // cout << "\n";
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << (matrix[x][y] == INF ? -1 : matrix[x][y]) << "\n";
    }

    return 0;
}
