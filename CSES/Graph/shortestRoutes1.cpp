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
    
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});flights are unidirectional
    }
    // vector<vector<pair<ll,ll>>> adj(n+1);
    // for(int i=0;i<m;i++){
    //     ll u = edges[i][0];
    //     ll v = edges[i][1];
    //     ll w = edges[i][2];
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }
    vector<ll> dist(n+1,LLONG_MAX);
    dist[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        if(dis>dist[node])continue;
        for(auto& it:adj[node]){
            ll adjNode = it.first;
            ll edgeWt = it.second;
            if(dist[node]+edgeWt<dist[adjNode]){
                dist[adjNode]=dis+edgeWt;
                pq.push({dis+edgeWt,adjNode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
