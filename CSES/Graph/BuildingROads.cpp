#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int &rep)
{
    vis[node] = 1;
    rep = node;
    for (auto &neigh : adj[node])
    {
        if (!vis[neigh])
        {
            dfs(neigh, vis, adj, rep);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    vector<int> vis(n + 1, 0);
    vector<int> reps;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int rep = i;
            dfs(i, vis, adj, rep);
            reps.push_back(rep);
            cnt++;
        }
    }

    cout << cnt - 1 << "\n";
    for (int i = 0; i < reps.size() - 1; i++)
    {
        cout << reps[i] << " " << reps[i + 1] << "\n";
    }

    return 0;
}
