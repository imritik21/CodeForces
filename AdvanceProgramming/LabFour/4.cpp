#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// Balanced Binary tree or Not
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};
int height(Node* root){
    if(root==NULL)return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}
bool check(Node* root){
    if(root==NULL) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)>1)return false;
    return check(root->left) && check(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
     //      1         1
    //     / \       / \
    //    2   3     3   2
    //                  \
    //                  6
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(5);

    cout<<height(root)<<endl;
    cout<<(check(root)?"YES":"NO")<<endl;
    return 0;
}
