#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    // priority
    vector<ll> arr(n);
    for(auto &i:arr){
        cin>>i;
        i=abs(i);
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    // for every lower l find max r i.e 2*l
    for(int i=0;i<n;i++){
        auto itr = upper_bound(arr.begin(),arr.end(),2*arr[i]);
        itr--;
        ans+= itr - arr.begin()-i;
    }
    cout<<ans<<endl;
    return 0;
}
