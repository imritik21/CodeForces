#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<int>> final;
vector<int> curr;
void subsetSum(vector<int>& nums,int n,int ind){
    if(ind == n){
        final.push_back(curr);
        return;
    }
    // without take
    subsetSum(nums,n,ind+1);
    curr.push_back(nums[ind]);
    subsetSum(nums,n,ind+1);
    curr.pop_back();
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++) cin>>nums[i];
    subsetSum(nums,n,0);
    for(int i=0;i<final.size();i++){
        for(int j=0;j<final[i].size();j++){
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
}
