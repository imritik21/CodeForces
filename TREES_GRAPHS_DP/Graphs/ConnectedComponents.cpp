#include <bits/stdc++.h>
using namespace std;
void dfs(int src,vector<int> adj[],vector<int>&vis){
	vis[src]=1;
	for(auto adjNode:adj[src]){
		if(!vis[adjNode]){
			dfs(adjNode,adj,vis);
		}
	}
}
int main() {
	
	int n,e;
	cin>>n>>e;
	vector<vector<int>> edges;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		edges.push_back({u,v});
	}
	vector<int> adj[n+1];
	for(auto edge:edges){
		int u = edge[0];
		int v = edge[1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	int cnt=0;
	for(int i=1;i<n+1;i++){
		if(!vis[i]){
			dfs(i,adj,vis);
			cnt++;
		}
	}
	cout<<cnt<<endl;
}