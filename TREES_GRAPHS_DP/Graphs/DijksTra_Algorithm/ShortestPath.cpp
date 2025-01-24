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
    
    vector<vector<pair<int,int>>> adj = {{{1,2},{3,1}},{{0,2},{2,4},{4,5}},{{1,4},{3,3},{4,1}},
                                {{0,1},{2,3}}, {{1,5},{2,1}}};
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int n = adj.size();
    vector<int> vis(n,0),dist(n,1e9),parent(n,0);
    for(int i=0;i<n;i++)parent[i]=i;
    vis[0]=1;
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(auto& it:adj[node]){
            int adjNode = it.first;
            int wt = it.second;

            if(dis+wt<dist[adjNode]){
                dist[adjNode] = dis+wt;
                pq.push({dist[adjNode],adjNode});
                parent[adjNode]=node;
            }
        }
    }
    parent[0]=0;
    if(dist[n-1]==1e9) return 0;
    vector<int> path;
    int node = n-1;
    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(0);
    reverse(path.begin(),path.end());
    for(auto& ele:path)cout<<ele<<" ";
    cout<<endl;
    return 0;
}
