#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    vector<int> dist(n + 1, 1e9);
    // m-1 time
    dist[0] = 0;
    for (int i = 0; i < m - 1; i++)
    {
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dist[u] != 1e9 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    // to detect negative cycle do this algo one more ime if it still gets updated then there's a cycle
    for (auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (dist[u] != 1e9 && dist[u] + w < dist[v])
        {
            cout<<"Negative Cycle"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)cout<<dist[i]<<endl;
    return 0;
}
