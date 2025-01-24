#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>& st){
    vis[node]=1;

    for(auto& neigh:adj[node]){
        if(!vis[neigh]){
            dfs(neigh,adj,vis,st);
        }
    }
    // after returning from node put it into the stack
    st.push(node);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> adj = {{},{},{3},{},{0,1},{0,2}};
    int n = adj.size();
    vector<int> vis(n,0);
    stack<int> st;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int> ordering;
    while(!st.empty()){
        ordering.push_back(st.top());
        st.pop();
    }
    for(auto& ele:ordering)cout<<ele<<" ";
    return 0;
}
