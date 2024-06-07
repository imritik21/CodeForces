struct Node {
    int data;
    Node* left;
    Node* right;
};

int kthAncestorHelper(Node* root, int k, int node, int& ancestor) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == node) {
        return 0; // Distance between the root and the node
    }

    int leftDist = kthAncestorHelper(root->left, k, node, ancestor);
    int rightDist = kthAncestorHelper(root->right, k, node, ancestor);

    if (leftDist == -1 && rightDist == -1) {
        return -1; // Node not found in either subtree
    }

    int currDist = (leftDist != -1) ? leftDist : rightDist;

    if (currDist + 1 == k) {
        ancestor = root->data;
    }

    return currDist + 1;
}

int kthAncestor(Node* root, int k, int node) {
    int ancestor = -1;
    kthAncestorHelper(root, k, node, ancestor);
    return ancestor;
}
