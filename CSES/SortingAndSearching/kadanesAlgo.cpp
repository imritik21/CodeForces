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
    
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(auto &it:arr)cin>>it;

    ll maxSubSum=INT_MIN;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSubSum=max(maxSubSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxSubSum<<endl;
    return 0;
}
