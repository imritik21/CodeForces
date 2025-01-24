#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<int> Dijkstra(vector<vector<pair<int,int>>>&adj,int src){
    int n = adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,1e9);
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto& neigh:adj[node]){
            int v = neigh.first;
            int wt = neigh.second;

            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<pair<int,int>>> adj = {{{1,1},{2,6}},{{2,3},{0,1}},{{1,3},{0,6}}};
    int src=2;
    vector<int> dist = Dijkstra(adj,src);
    for(auto& ele:dist)cout<<ele<<" ";
    cout<<endl;
    return 0;
}
