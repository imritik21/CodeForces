#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool bfs(int src,vector<vector<int>>adj,vector<int>&vis){
    queue<int> q;
    // vector<int> vis(adj.size(),0);
    vis[src]=0;
    q.push(src);

    while(!q.empty()){
        int node= q.front();
        q.pop();

        for(auto& neigh:adj[node]){
            if(vis[neigh]==-1){
                vis[neigh]=!vis[neigh];
                q.push(neigh);
            }
            else if(vis[neigh]==vis[node]){ //  same color
                return false;
            }
        }
    }
    return true;
}
bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int col){
    vis[node]=col;
    for(auto& neigh:adj[node]){
        if(vis[neigh]==-1){
            if (dfs(neigh, adj, vis, !col))return false;
        }
        else if(vis[neigh]==vis[node]){
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    vector<vector<int>> adj = { {1, 2, 3},
                                { 0, 2 },
                                { 0, 1, 3 },
                                { 0, 2 } };
    int n = adj.size();
    // in bfs we will start from 1st node or for every component lets run the loop
    vector<int> vis(n,-1);// use this as a color array
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            if(!dfs(i,adj,vis,0)){
                cout<<"false"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES Bipartite"<<endl;

    return 0;
}
