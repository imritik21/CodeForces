#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
Find the shortest path from src(0) vertex to all the vertices and
if it is impossible to reach any vertex, then return -1 for that vertex.
*/
// USING TOPO SORT because
    // it ensures that by the time you go to the vertex you've already processed
    // previous node to it
    // using DFS Stack to calculate topo and then taking each ele from top
    // of the stack and processing it it reduces TC , reducing the checks
void dfsCheck(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        int neigh = it.first;
        if (!vis[neigh])
        {
            dfsCheck(neigh, adj, vis, st);
        }
    }
    st.push(node);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V = 4, E = 2;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}};
    
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
    }
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, adj, vis, st);
        }
    }
    vector<int> dist(V, 1e9);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto &ele : adj[node])
        {
            int v = ele.first;
            int wt = ele.second;
            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    for(auto& ele:dist)cout<<ele<<" ";
    return 0;
}
