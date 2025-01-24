#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int color){
    vis[node]=color;
    for(auto& neigh:adj[node]){
        if(!vis[neigh]){
            if(!dfs(neigh,vis,adj,3-color))return false;
        }
        if(vis[neigh]==vis[node])return false;        
    }
    return true;
}
bool isBipartite(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int> vis(n,0);

    /// for all comp
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(!dfs(i,vis,adj,1))return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> adj = {{1},{0,2},{1}};
    cout<<(isBipartite(adj)?"YES":"NO")<<endl;    
    return 0;
}
