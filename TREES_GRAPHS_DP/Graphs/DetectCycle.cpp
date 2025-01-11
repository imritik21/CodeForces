#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool dfs(int node,int par,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,adj,vis)) return true;
        }
        else if(it!=par){
            // vis but not it's parent means cycle
            return true;
        }
    }
    return false;
}

bool bfs(int src,vector<vector<int>>&adj,vector<int>& vis){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                q.push({adjNode,node});
            }
            else if(adjNode!=par){
                /// already visited but not its parent
                // means someone else visited it on same/prev level
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> adj = {{1},{0,2,4},{1,3},{2,4},{1,3}};
    int n = adj.size();
    vector<int> vis(n,0);

    bool cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            // if(dfs(i,-1,adj,vis)){
            //     cycle=true;
            //     break;
            // }
            if(bfs(i,adj,vis)){
                cycle=true;
                break;
            }
        }
    }
    if(cycle){
        cout<<"Cycle exists "<<endl;
    }
    else cout<<"Cycle doesn't exists "<<endl;
    return 0;
}
