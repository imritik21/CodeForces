#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void dfs(int curr,vector<bool>&vis,vector<int> graph[]){
    vis[curr]=true;
    cout<<curr<<" ";
    for(auto ele:graph[curr]){
        if(vis[ele]==true)continue;
        dfs(ele,vis,graph);
    }
}
bool hasPath(int src,int dest,vector<int>&vis,vector<int> graph[]){
    if(src==dest){
        return true;
    }
    vis[src]=true;
    // now visit its neighbour if they found 
    // return true 
    for(auto neigh:graph[src]){
        if(!vis[neigh] && hasPath(neigh,dest,vis,graph)){
            return true;
        }
    }
    return false;
}
int main()
{   
    // we need to identify whether there exits a
    // path between src and est or not
    // lets solve
    int n,m;
    cin>>n>>m;
    // 0 1    2 4  5 6
    // 0 2    3 4
    // 1 3    3 5
    vector<int> graph[n];
    for(int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,graph);
        }
    }
    return 0;
}
