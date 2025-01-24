#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// Safe states means it should end at terminal node
// Not safe cond:
// 1. involved in cycle
// 2. node incoming into cycle as it would always end in being cycle
bool dfsCheck(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;// initially starts with 0
    for(auto& neigh:graph[node]){
        if(!vis[neigh]){
            if(dfsCheck(neigh,graph,vis,pathVis,check)==true){
                // definetly a cycle/involved
                check[node]=0;
                return true;
            }
        }
        if(pathVis[neigh]){
            // already vis by someother
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;// while backtarcking undo it 
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    int n = graph.size();
    vector<int> vis(n,0),pathVis(n,0),check(n,0);
    vector<int> safeState;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsCheck(i,graph,vis,pathVis,check);
        }
    }
    for(int i=0;i<n;i++){
        if(check[i]==1){
            // safeState.push_back(i);
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}
