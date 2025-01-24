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
    
    vector<vector<int>> adj = {{},{},{3},{1},{0,1},{0,2}};
    int n = adj.size();
    vector<int> indegree(n,0);

    for(int i=0;i<n;i++){
        for(auto& it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sort
        // so please remove it from your indegree
        for(auto& it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }

    for(auto& ele:topo)cout<<ele<<" ";
    return 0;
}
