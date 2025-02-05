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

    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dest = 3, k= 1;
    // return cheapest price from src to dest with at most k stops
    // here generic dikjstra will fail as the priority would be distance not the stops
    // so our priority should be the no of min stops
    // conv into adj list
    int n = flights.size();
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int cost = flights[i][2];
        adj[u].push_back({v,cost});
        // adj[v].push_back({u,cost}); // its directed 
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{src,0}});
    vector<int> dist(n,1e9);
    dist[src]=0;
    while(!pq.empty()){
        int stop = pq.top().first;
        int node = pq.top().second.first;
        int cost = pq.top().second.second;
        pq.pop();

        if(stop>k){
            continue;
        }
        for(auto& it:adj[node]){
            int adjNode =  it.first;
            int edgeCost = it.second;

            if(cost+edgeCost<dist[adjNode] && stop<=k){
                dist[adjNode] = cost+edgeCost;
                pq.push({stop+1,{adjNode,cost+edgeCost}});
            }
        }
    }
    if(dist[dest]==1e9){
        cout<<-1<<endl;
    }
    cout<<dist[dest]<<endl;
    return 0;
}
