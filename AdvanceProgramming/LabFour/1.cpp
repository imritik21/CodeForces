#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// convert into mirror Tree
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void mirror(Node* root){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        return;
    }
    Node *x = root->left;
    Node *y = root->right;

    mirror(root->left);
    mirror(root->right);

    root->left = y;
    root->right = x;
    return;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //      1         1
    //     / \       / \
    //    2   3     3   2
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    inorder(root);
    cout<<endl;
    mirror(root);
    inorder(root);
    
    return 0;
}
