// // // #include <iostream>
// // // #include <vector>
// // // #include <unordered_set>

// // // using namespace std;

// // // const int MOD = 1e9 + 7;

// // // vector<vector<int>> tree; // Adjacency list of the tree
// // // vector<int> values; // Values of the nodes
// // // vector<int> subtreeRanges; // Number of covered ranges for each node

// // // // Function to perform DFS and compute the number of covered ranges
// // // void dfs(int node) {
// // //     unordered_set<int> uniqueValues;
// // //     uniqueValues.insert(values[node]);

// // //     for (int child : tree[node]) {
// // //         dfs(child);
// // //         // Collect unique values from child subtrees
// // //         unordered_set<int> childValues;
// // //         for (int val : uniqueValues) {
// // //             childValues.insert(val);
// // //         }
// // //         for (int val : subtreeRanges) {
// // //             childValues.insert(val);
// // //         }
// // //         uniqueValues = move(childValues);
// // //     }

// // //     subtreeRanges[node] = uniqueValues.size();
// // // }

// // // int main() {
// // //     int N;
// // //     cin >> N;

// // //     vector<int> P(N), A(N);
// // //     tree.resize(N);
// // //     subtreeRanges.resize(N, 0);
// // //     values.resize(N);

// // //     // Reading parent array
// // //     for (int i = 0; i < N; ++i) {
// // //         cin >> P[i];
// // //     }

// // //     // Reading values array
// // //     for (int i = 0; i < N; ++i) {
// // //         cin >> A[i];
// // //         values[i] = A[i];
// // //     }

// // //     // Building tree
// // //     for (int i = 1; i < N; ++i) {
// // //         tree[P[i]].push_back(i);
// // //     }

// // //     // Perform DFS from the root (node 0)
// // //     dfs(0);

// // //     // Compute the sum of all ranges
// // //     long long totalRanges = 0;
// // //     for (int range : subtreeRanges) {
// // //         totalRanges = (totalRanges + range) % MOD;
// // //     }

// // //     cout << totalRanges << endl;

// // //     return 0;
// // // }
// // #include <iostream>
// // #include <vector>
// // #include <unordered_set>
// // #include <algorithm>
// // using namespace std;

// // const int MOD = 1e9 + 7;

// // void dfs(int node, const vector<vector<int>>& tree, const vector<int>& A, vector<long long>& R) {
// //     unordered_set<int> unique_values;
    
// //     // Traverse the subtree
// //     for (int child : tree[node]) {
// //         dfs(child, tree, A, R);
// //         // Merge the unique values from the child
// //         unique_values.insert(R[child]);
// //     }
    
// //     // Add the value of the current node
// //     unique_values.insert(A[node]);
    
// //     // The number of covered ranges is the size of unique values
// //     R[node] = unique_values.size();
// // }

// // int main() {
// //     int N;
// //     cin >> N;
    
// //     vector<int> P(N), A(N);
// //     for (int i = 0; i < N; ++i) {
// //         cin >> P[i];
// //     }
// //     for (int i = 0; i < N; ++i) {
// //         cin >> A[i];
// //     }
    
// //     // Build the tree
// //     vector<vector<int>> tree(N);
// //     for (int i = 1; i < N; ++i) { // Start from 1 since P[0] = 0
// //         tree[P[i]].push_back(i);
// //     }
    
// //     // Vector to store the number of covered ranges for each node
// //     vector<long long> R(N, 0);
    
// //     // Perform DFS from the root (node 0)
// //     dfs(0, tree, A, R);
    
// //     // Calculate the sum of R values
// //     long long total_sum = 0;
// //     for (int i = 0; i < N; ++i) {
// //         total_sum = (total_sum + R[i]) % MOD;
// //     }
    
// //     cout << total_sum << endl;
    
// //     return 0;
// // }
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// const int MOD = 1e9 + 7;

// void dfs(int node, const vector<vector<int>>& tree, const vector<int>& A, vector<long long>& R) {
//     // Use a set to track unique values in the subtree
//     unordered_set<int> unique_values;
    
//     // Add the value of the current node
//     unique_values.insert(A[node]);
    
//     // Traverse the subtree
//     for (int child : tree[node]) {
//         dfs(child, tree, A, R);
//         // Merge the unique values from the child
//         unique_values.insert(A[child]); // Only insert the value of the child node
//     }
    
//     // The number of covered ranges is the size of unique values
//     R[node] = unique_values.size();
// }

// int main() {
//     int N;
//     cin >> N;
    
//     vector<int> P(N), A(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> P[i];
//     }
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }
    
//     // Build the tree
//     vector<vector<int>> tree(N);
//     for (int i = 1; i < N; ++i) { // Start from 1 since P[0] = 0
//         tree[P[i]].push_back(i);
//     }
    
//     // Vector to store the number of covered ranges for each node
//     vector<long long> R(N, 0);
    
//     // Perform DFS from the root (node 0)
//     dfs(0, tree, A, R);
    
//     // Calculate the sum of R values
//     long long total_sum = 0;
//     for (int i = 0; i < N; ++i) {
//         total_sum = (total_sum + R[i]) % MOD;
//     }
    
//     cout << total_sum << endl;
    
//     return 0;
// }
#include <iostream>
#include <vector>
#include <unordered_set>

const int MOD = 1e9 + 7;

using namespace std;

vector<vector<int>> tree;
vector<int> values;
vector<int> result;

void dfs(int node) {
    unordered_set<int> uniqueValues;
    uniqueValues.insert(values[node]);
    
    for (int child : tree[node]) {
        dfs(child);
        uniqueValues.insert(result[child]);
    }
    
    result[node] = uniqueValues.size();
}

int main() {
    int N;
    cin >> N;
    
    vector<int> P(N), A(N);
    tree.resize(N);
    result.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    values = A;
    
    // Build the tree
    for (int i = 1; i < N; i++) {
        tree[P[i]].push_back(i);
    }
    
    // Start DFS from the root node (0)
    dfs(0);
    
    // Calculate the final result
    long long totalCoveredRanges = 0;
    for (int r : result) {
        totalCoveredRanges = (totalCoveredRanges + r) % MOD;
    }
    
    cout << totalCoveredRanges << endl;
    return 0;
}
