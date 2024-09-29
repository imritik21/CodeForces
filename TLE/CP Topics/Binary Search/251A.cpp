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

    ll n,d;
    cin>>n>>d;
    ll ans=0;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    // fix rigfhtmosdt and find the combinations
    for(int i=2;i<n;i++){
        int idx = lower_bound(arr.begin(),arr.end(),arr[i]-d)-arr.begin();
        ll temp = abs(idx-i);
        if(temp>=2){
            ans+=(temp*(temp-1))/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
