#include <bits/stdc++.h>
using namespace std;

// Helper function to perform BFS starting from a specific node
void bfsHelper(int start, vector<int> adj[], vector<bool>& vis, vector<int>& ans) {
    queue<int> q;
    q.push(start); // Start BFS from the given node
    vis[start] = true; // Mark the starting node as visited

    while (!q.empty()) {
        int curr = q.front(); // Get the front element of the queue
        q.pop(); // Remove the front element

        ans.push_back(curr); // Add the current node to the result

        // Visit all neighbors of the current node
        for (int i = 0; i < adj[curr].size(); i++) {
            int neigh = adj[curr][i];
            if (!vis[neigh]) { // If the neighbor hasn't been visited
                q.push(neigh); // Push it onto the queue
                vis[neigh] = true; // Mark it as visited
            }
        }
    }
}

// Function to perform BFS for the entire graph
void bfs(int V, vector<int> adj[], vector<int>& ans) {
    vector<bool> vis(V, false); // Visited array to track visited nodes

    // Traverse all nodes in case the graph is disconnected
    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // If the node hasn't been visited
            bfsHelper(i, adj, vis, ans); // Perform BFS from this node
        }
    }
}

// Function to return Breadth First Traversal of the graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans; // Vector to store the BFS traversal result
    bfs(V, adj, ans); // Perform BFS for the graph
    return ans; // Return the BFS traversal result
}

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation

    // Adding edges (example graph)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(4);
    
    // Get the BFS traversal of the graph
    vector<int> result = bfsOfGraph(V, adj);

    // Print the BFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}
