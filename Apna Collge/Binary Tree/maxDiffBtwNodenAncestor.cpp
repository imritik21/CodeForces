#include <iostream>
#include<bits/stdc++.h>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

int maxDiffUtil(Node* node, int* res) {
    // Base case: when node is NULL, return a very large value
    if (node == NULL) {
        return INT_MAX;
    }

    // If leaf node, return its value
    if (node->left == NULL && node->right == NULL) {
        return node->data;
    }

    // Recur for left and right subtrees
    int leftMin = maxDiffUtil(node->left, res);
    int rightMin = maxDiffUtil(node->right, res);

    // Find the minimum value in left and right subtrees
    int minDescendant = min(leftMin, rightMin);

    // Update the result if needed
    *res = max(*res, node->data - minDescendant);

    // Return the minimum value found so far
    return min(node->data, minDescendant);
}

int maxDiff(Node* root) {
    // Initialize result
    int res = INT_MIN;

    // Call the recursive helper function
    maxDiffUtil(root, &res);

    return res;
}
void solve(Node *root,vector<int>& res){
    if(root == NULL){
        return;
    }
    if(root->right != NULL){
        res.push_back(root->right->data);
    }
    solve(root->left,res);
    
    solve(root->right,res);
    
}
vector<int> rightView(Node *root)
{
   // Your Code here
   vector<int> res;
   res.push_back(root->data);
   solve(root,res);
   return res;
}
// Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        Node *x = root->left;
        Node *y = root->right;
        
        mirror(root->left);
        mirror(root->right);
        
        root->left = y;
        root-> right =x;
        return;
    }
// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    /*
              8
            /  \
           3    10
          / \     \
         1   6     14
            / \    /
           4   7  13
    */
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    // cout << "Maximum difference between a node and its ancestor is: " << maxDiff(root) << endl;
    vector<int> res = rightView(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
