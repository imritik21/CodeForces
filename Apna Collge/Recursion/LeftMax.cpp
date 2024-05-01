#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void helper(int i,int mx,vector<int>& arr,int n){
    if(i==n) return;
    mx=max(mx,arr[i]);
    cout<<mx<<" ";
    return helper(i+1,mx,arr,n);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    helper(0,INT_MIN,arr,n);
}
