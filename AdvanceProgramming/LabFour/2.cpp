#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// Diameter of a binary TRee
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};
// int ans=0;
int Diameter(Node* root,int maxi){
    // lh + rh + 1 
    // leaf to 0
    if(root==NULL){
        return 0;
    }
    int lh = Diameter(root->left,maxi);
    int rh = Diameter(root->right,maxi);
    
    return max(lh,rh)+1;
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
    root->right->left = new Node(6);

    int ans=0;
    cout<<Diameter(root,ans)<<endl;
    return 0;
}
