#include <bits/stdc++.h>
using namespace std;

// BST Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void findKthLargest(Node* root, int& cnt, int kth, int& ele) {
    if (root == NULL || cnt > kth) return;

    findKthLargest(root->left, cnt, kth, ele);

    cnt++;
    
    if (cnt == kth) {
        ele = root->data;
        return;
    }

    findKthLargest(root->right, cnt, kth, ele);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //   BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    int k = 3; 
    int n = 5;
    int kth = n - k + 1; 
    int cnt = 0; 
    int ele = -1; 

    findKthLargest(root, cnt, kth, ele);

    cout<<ele<<endl;

    return 0;
}
