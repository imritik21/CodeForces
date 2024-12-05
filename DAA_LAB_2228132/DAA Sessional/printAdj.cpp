#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class CreatingGraph {
    public:
        class Edge { 
            public:
                int src, dest, wt;
                Edge(int s, int d, int w) : src(s), dest(d), wt(w) {}
        };

        // Method to create a set of edges with weights
        void createGraph(int v, vector<Edge>& edges) {
            edges.push_back(Edge(0, 1, 2));
            edges.push_back(Edge(0, 4, 1));
            edges.push_back(Edge(1, 2, 4));
            edges.push_back(Edge(1, 3, 7));
            edges.push_back(Edge(3, 2, 1));
            edges.push_back(Edge(4, 1, 3));
            edges.push_back(Edge(4, 3, 5));
        }

        // Method to generate and return the adjacency list
        vector<vector<pair<int, int>>> printadj(int v, vector<Edge>& edges) {
            vector<vector<pair<int, int>>> adj(v);

            for (const Edge& e : edges) {
                adj[e.src].push_back({e.dest, e.wt});
                adj[e.dest].push_back({e.src, e.wt});  // Assuming undirected graph
            }
            return adj;
        }

        // Dijkstra’s Algorithm for Shortest Path
        void dijkstra(int v, vector<vector<pair<int, int>>>& adj, int src) {
            vector<int> dist(v, INT_MAX);
            vector<bool> vis(v, false);
            dist[src] = 0;

            // Min-heap for shortest distance
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [currDist, u] = pq.top();
                pq.pop();

                if (vis[u]) continue;
                vis[u] = true;

                for (auto& [v, wt] : adj[u]) {
                    if (!vis[v] && currDist + wt < dist[v]) {
                        dist[v] = currDist + wt;
                        pq.push({dist[v], v});
                    }
                }
            }

            // Display shortest distance from source to each vertex
            cout << "Shortest distances from source " << src << ":\n";
            for (int i = 0; i < v; i++) {
                cout << "Vertex " << i << " : " << dist[i] << "\n";
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int v = 5;
    vector<CreatingGraph::Edge> edges;
    CreatingGraph graph;
    graph.createGraph(v, edges);
    
    // Generate adjacency list
    vector<vector<pair<int, int>>> adj = graph.printadj(v, edges);

    // Print the adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (const auto& [neighbor, weight] : adj[i]) {
            cout << "(" << neighbor << ", " << weight << ") ";
        }
        cout << endl;
    }

    // Run Dijkstra’s algorithm from source vertex 0
    int src = 0;
    graph.dijkstra(v, adj, src);

    return 0;
}
