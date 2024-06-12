
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;
double eps = 1e-12;
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll h,n;
    cin>>h>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++) h-=a[i];
    if(h<=0){
        cout<<1<<endl;
        return;
    }
    ll l=0;
    ll r=1e18;
    ll ans;
    while(l<=r){
        ll mid = (l+r)>>1;
        ll s = 0;
        // for every 
        for(int i=0;i<n;i++){
            s+=(mid/b[i])*a[i];
        }
        if(h-s<=0){
            ans=mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans+1<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}