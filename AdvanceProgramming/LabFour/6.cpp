#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool dfsCheck(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;

    for(auto& neigh:adj[node]){
        if(!vis[neigh]){
            if(dfsCheck(neigh,adj,vis,pathVis))return true;
        }
        else if(pathVis[node]){
            return true;
        }
    }
    pathVis[node]=0; // after backtrack undo the pathVis
    return false;
}
bool DetectCycles(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int> vis(n,0),pathVis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfsCheck(i,adj,vis,pathVis))return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    vector<vector<int>> adj = {{1},{2},{3,6},{4},{5},{},{4},{8,1},{9},{7}};
    // 0--1--2--3
    //   |   |  |
    //   7   6--4--5
    //  | \
    //  8--9
    cout<<(DetectCycles(adj)?"YES\n":"NO\n")<<endl;
    return 0;
}
