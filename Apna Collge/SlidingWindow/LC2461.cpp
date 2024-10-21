#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // vector<int> arr = {1,5,4,2,9,9,9};
    vector<int> arr = {3,3,3};
    int n = arr.size();
    int k = 3;

    map<int,int> mp;
    int maxSum=0;
    int sum=0;
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
        sum+=arr[i];
        if(mp.size()==k){
            maxSum=max(maxSum,sum);
        }
    }
    // maxSum=sum;
    for(int i=k;i<n;i++){
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0){
            mp.erase(arr[i-k]);
        }
        sum-=arr[i-k];
        mp[arr[i]]++;
        sum+=arr[i];
        if(mp.size()==k){
            maxSum=max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}
