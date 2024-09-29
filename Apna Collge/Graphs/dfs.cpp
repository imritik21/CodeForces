#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasPath(vector<vector<int>>& adj, int src, int dest, vector<bool>& vis) {
        if (src == dest) {
            return true;  // Base case: found a path
        }
        vis[src] = true;  // Mark the current node as visited
        
        // Visit all neighbors of the current node
        for (int i = 0; i < adj[src].size(); i++) {
            int neigh = adj[src][i];
            if (!vis[neigh] && hasPath(adj, neigh, dest, vis)) {
                return true;  // Found a path through one of the neighbors
            }
        }
        return false;  // No path found from this node
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        // Create an adjacency list from the edge list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);  // Since the graph is undirected
        }
        
        vector<bool> vis(n, false);  // Visited array to keep track of visited nodes
        return hasPath(adj, source, dest, vis);  // Start the DFS from the source node
    }
};

// Depth-First Search helper function
void dfs(vector<int> adj[], vector<int>& ans, int curr, vector<bool>& vis) {
    ans.push_back(curr); // Add the current node to the DFS traversal result
    vis[curr] = true;    // Mark the current node as visited
    
    // Visit all the neighbors of the current node
    for (int i = 0; i < adj[curr].size(); i++) {
        int neigh = adj[curr][i];
        if (!vis[neigh]) { // If the neighbor hasn't been visited, continue DFS
            dfs(adj, ans, neigh, vis);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;         // Vector to store the DFS traversal result
    vector<bool> vis(V, false); // Visited array to track visited nodes
    
    // Start DFS from the first node (usually 0 if 0-indexed graph)
    dfs(adj, ans, 0, vis);
    
    return ans; // Return the DFS traversal result
}

int main() {
    // Example usage
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation

    // Adding edges (example graph)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    
    // Get the DFS traversal of the graph
    vector<int> result = dfsOfGraph(V, adj);

    // Print the DFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}
