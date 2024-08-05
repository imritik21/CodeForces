// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// #include <unordered_map>

// using namespace std;

// const long long INF = LLONG_MAX;

// struct Node {
//     int index;
//     long long cost;
//     bool operator>(const Node& other) const {
//         return cost > other.cost;
//     }
// };

// long long find_min_cost(int N, vector<int>& A) {
//     priority_queue<Node, vector<Node>, greater<Node>> pq;
//     vector<long long> min_cost(N + 1, INF);
//     unordered_map<int, vector<int>> multiples;

//     // Initialize the priority queue
//     pq.push({1, 0});
//     min_cost[1] = 0;

//     // Build a map of multiples
//     for (int i = 1; i <= N; ++i) {
//         for (int j = i + 1; j <= N; ++j) {
//             if (A[j - 1] % A[i - 1] == 0) {
//                 multiples[i].push_back(j);
//             }
//         }
//     }

//     while (!pq.empty()) {
//         Node current = pq.top();
//         pq.pop();

//         if (current.index == N) {
//             return current.cost;
//         }

//         // Move to the next position
//         if (current.index < N && current.cost + 1 < min_cost[current.index + 1]) {
//             min_cost[current.index + 1] = current.cost + 1;
//             pq.push({current.index + 1, min_cost[current.index + 1]});
//         }

//         // Jump to multiples
//         for (int next : multiples[current.index]) {
//             long long new_cost = current.cost + A[next - 1];
//             if (new_cost < min_cost[next]) {
//                 min_cost[next] = new_cost;
//                 pq.push({next, new_cost});
//             }
//         }
//     }

//     return -1; // If no valid path is found
// }

// int main() {
//     int N;
//     cin >> N;
//     vector<int> A(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }

//     cout << find_min_cost(N, A) << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

struct Node {
    int index;
    long long cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

long long find_min_cost(int N, vector<int>& A) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<long long> min_cost(N + 1, INF);
    unordered_map<int, vector<int>> multiples;

    // Initialize the priority queue
    pq.push({1, 0});
    min_cost[1] = 0;

    // Build a map of multiples
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (A[j - 1] % A[i - 1] == 0) {
                multiples[i].push_back(j);
            }
        }
    }

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.index == N) {
            return current.cost;
        }

        // Move to the next position
        if (current.index < N) {
            long long next_cost = current.cost + 1;
            if (next_cost < min_cost[current.index + 1]) {
                min_cost[current.index + 1] = next_cost;
                pq.push({current.index + 1, next_cost});
            }
        }

        // Jump to multiples
        for (int next : multiples[current.index]) {
            long long new_cost = current.cost + A[next - 1];
            if (new_cost < min_cost[next]) {
                min_cost[next] = new_cost;
                pq.push({next, new_cost});
            }
        }
    }

    return -1; // If no valid path is found
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << find_min_cost(N, A) << endl;
    return 0;
}
