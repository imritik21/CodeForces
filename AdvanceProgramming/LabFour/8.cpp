#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

vector<int> diameterNodes; // Global vector to store nodes in the diameter

// Function to calculate the diameter and store nodes
int Diameter(Node* root, int &maxi, vector<int>& path) {
    if (root == NULL) {
        return 0;
    }

    vector<int> leftPath, rightPath;

    int lh = Diameter(root->left, maxi, leftPath);
    int rh = Diameter(root->right, maxi, rightPath);

    // If the current diameter is larger, update it and store the path
    if (lh + rh + 1 > maxi) {
        maxi = lh + rh + 1;
        diameterNodes.clear();
        diameterNodes.insert(diameterNodes.end(), leftPath.rbegin(), leftPath.rend()); // Reverse left path
        diameterNodes.push_back(root->data);
        diameterNodes.insert(diameterNodes.end(), rightPath.begin(), rightPath.end());
    }

    // Return the height and construct the current path
    if (lh > rh) {
        path = leftPath;
    } else {
        path = rightPath;
    }
    path.push_back(root->data);

    return max(lh, rh) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);

    int ans = 0;
    vector<int> tempPath;
    Diameter(root, ans, tempPath);

    cout << "Diameter Length: " << ans << endl;
    cout << "Nodes in Diameter: ";
    for (auto node : diameterNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
