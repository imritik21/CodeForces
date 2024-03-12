#include <iostream>
#include <vector>

std::vector<int> colors;
std::vector<std::vector<int>> graph;

bool dfs(int node, int color) {
    colors[node] = color;

    for (int neighbor : graph[node]) {
        if (colors[neighbor] == color) {
            return false;  // Samarth's condition is violated
        }

        if (colors[neighbor] == 0 && !dfs(neighbor, 3 - color)) {
            return false; 
        }
    }

    return true;  
}

int main() {
    int N, M;
    std::cin >> N >> M;

    colors.resize(N + 1, 0);
    graph.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (int i = 1; i <= N; ++i) {
        if (colors[i] == 0 && !dfs(i, 1)) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    for (int i = 1; i <= N; ++i) {
        std::cout << colors[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}