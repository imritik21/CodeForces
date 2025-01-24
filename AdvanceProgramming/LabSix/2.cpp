// Given an undirected graph and a number n the
// task is to colour the given graph with such that
// no two adjacent
// vertices of the graph are coloured with same colour

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007
// bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int color){
//     vis[node]=color;
//     for(auto& neigh:adj[node]){
//         if(!vis[neigh]){
//             if(!dfs(neigh,vis,adj,3-color))return false;
//         }
//         if(vis[neigh]==vis[node])return false;        
//     }
//     return true;
// }
// bool isBipartite(vector<vector<int>>&adj){
//     int n = adj.size();
//     vector<int> vis(n,0);

//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(!dfs(i,vis,adj,1))return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     vector<vector<int>> adj = {{1},{0,2},{1}};
//     cout<<(isBipartite(adj)?"YES":"NO")<<endl;    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj, int c) {
    for (auto &neigh : adj[node]) {
        if (color[neigh] == c) 
            return false;
    }
    return true;
}

bool colorGraphInOrder(vector<vector<int>> &adj, vector<int> &order, vector<int> &color, int m) {
    for (int node : order) {
        bool colored = false;
        for (int c = 1; c <= m; c++) { 
            if (isSafe(node, color, adj, c)) {
                color[node] = c;
                colored = true;
                break;
            }
        }
        if (!colored) { // If no valid color found
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> adj = {
        {1, 3},  
        {0, 2}, 
        {1, 3}, 
        {0, 2}
    };

    int m = 2; 
    vector<int> order = {0, 1, 2, 3}; // Order in which nodes need to be colored
    vector<int> color(adj.size(), 0); // Color array

    if (colorGraphInOrder(adj, order, color, m)) {
        for (int i = 0; i < color.size(); i++) {
            cout << "Node " << i << ": Color " << color[i] << "\n";
        }
    } else {
        cout << "Graph cannot be colored \n";
    }

    return 0;
}

