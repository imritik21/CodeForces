#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// check for every node wheter its value is equal to 
// the sum of its left and right child
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};
bool IsAllNodeEqualToSumOfChild(Node* root){
    if(root==NULL)return true; 

    if(root->left==NULL && root->right==NULL){
        return true; // excluding leaf Node
    }

    int leftVal = root->left?root->left->data:0;
    int rightVal = root->right?root->right->data:0;

    if(root->data != leftVal+rightVal)return false;
    
    return IsAllNodeEqualToSumOfChild(root->left)&&IsAllNodeEqualToSumOfChild(root->right);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //      1         1
    //     / \       / \
    //    2   3     3   2
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);

    cout<<(IsAllNodeEqualToSumOfChild(root)?"YES":"NO")<<endl;
    return 0;
}
