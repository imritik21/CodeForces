#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int countPaths(int n, vector<vector<int>>& roads){
    // undirected graph and we have to count no of shortest path
    // so we'll take a ways array and find how many shortest ways did
    // it took to reach Nth node 
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<roads.size();i++){
        int u = roads[i][0];
        int v = roads[i][1];
        int cost = roads[i][2];
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }

    vector<int> dist(n,1e9);
    vector<int> ways(n,0);
    dist[0]=0;
    ways[0]=1;// always a way to reach 0
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto& it:adj[node]){
            int adjNode = it.first;
            int edgeTime = it.second;

            if(time+edgeTime<dist[adjNode]){
                dist[adjNode] = time+edgeTime;
                pq.push({dist[adjNode],adjNode});
                ways[adjNode] = ways[node]; // dependent to node
            }
            else if(time+edgeTime==dist[adjNode]){
                ways[adjNode]+=ways[node];
            }
        }
    }
    return ways[n-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout<<countPaths(n,roads)<<endl;
    return 0;
}
