#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<int>> final;
vector<int> curr;
int sum=0;
int sumOfsubset(vector<int> arr){
    int n = arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int xorSum(vector<int> arr){
    int n = arr.size();
    // if(n==1){
    //     return arr[0];
    // }
    if(n==0){
        return 0;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum^=arr[i];
    }
    return sum;
}
void subsetSum(vector<int>& nums,int n,int ind){
    if(ind == n){
        // sum+=sumOfsubset(curr);
        sum+=xorSum(curr);
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
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    subsetSum(nums,n,0);
    for(int i=0;i<final.size();i++){
        for(int j=0;j<final[i].size();j++){
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"sum: "<<sum<<endl;
}
