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
    
    vector<int> nums = {1,1,1};
    int k=4;
    // return total no. of subarrays with sum equals k
    int n = nums.size();
    map<int,int> mp;
    mp[0]=1;
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        int req = sum-k;
        if(mp.find(req)!=mp.end()){
            cnt+=mp[req];
        }
        mp[sum]++;
    }
    cout<<cnt<<endl;
    return 0;
}
