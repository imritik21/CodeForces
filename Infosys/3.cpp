// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <unordered_map>
// #include <algorithm>

// using namespace std;

// const int MOD = 1e9 + 7;

// // Tree node structure
// struct TreeNode {
//     int value;
//     vector<int> children;
// };

// // Function to perform DFS and compute the number of covered ranges
// int dfs(int node, const vector<int>& A, const vector<vector<int>>& tree, vector<int>& subtreeRanges) {
//     unordered_set<int> values;
//     values.insert(A[node]);
    
//     for (int child : tree[node]) {
//         dfs(child, A, tree, subtreeRanges);
//         for (int v : values) {
//             values.insert(v);
//         }
//     }
    
//     subtreeRanges[node] = values.size();
//     return subtreeRanges[node];
// }

// int main() {
//     int N;
//     cin >> N;
    
//     vector<int> P(N), A(N);
//     vector<vector<int>> tree(N);
    
//     // Reading parent array
//     for (int i = 0; i < N; ++i) {
//         cin >> P[i];
//     }
    
//     // Reading values array
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }
    
//     // Building tree
//     for (int i = 1; i < N; ++i) {
//         tree[P[i]].push_back(i);
//     }
    
//     vector<int> subtreeRanges(N, 0);
    
//     // Perform DFS from the root (node 0)
//     dfs(0, A, tree, subtreeRanges);
    
//     // Compute the sum of all ranges
//     long long totalRanges = 0;
//     for (int range : subtreeRanges) {
//         totalRanges = (totalRanges + range) % MOD;
//     }
    
//     cout << totalRanges << endl;
    
//     return 0;
// }
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> subtreeRanges;
vector<vector<int>> tree;
vector<int> values;

// Function to perform DFS and compute the number of covered ranges
void dfs(int node) {
    unordered_set<int> uniqueValues;
    uniqueValues.insert(values[node]);

    for (int child : tree[node]) {
        dfs(child);
        for (int val : uniqueValues) {
            uniqueValues.insert(val); // Merging the values from the child subtree
        }
    }

    subtreeRanges[node] = uniqueValues.size();
}

int main() {
    int N;
    cin >> N;

    vector<int> P(N), A(N);
    tree.resize(N);
    subtreeRanges.resize(N);
    values.resize(N);

    // Reading parent array
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Reading values array
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        values[i] = A[i];
    }

    // Building tree
    for (int i = 1; i < N; ++i) {
        tree[P[i]].push_back(i);
    }

    // Perform DFS from the root (node 0)
    dfs(0);

    // Compute the sum of all ranges
    long long totalRanges = 0;
    for (int range : subtreeRanges) {
        totalRanges = (totalRanges + range) % MOD;
    }

    cout << totalRanges << endl;

    return 0;
}
