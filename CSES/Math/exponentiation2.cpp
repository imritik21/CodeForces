
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int mod = 1e9+7;
ll mul(ll a,ll b){
    return (a*1LL*b)%mod;
}
ll power(ll a,ll b,ll m){
    ll ans = 1;
    
    while(b>0){
        // if(b&1) ans=mul(ans,a)%m;
        // a=mul(a,a)%m;
        if(b&1) ans=(ans*a)%m;
        a=(a*a)%m;
        b=b>>1;
    }
    return ans;
}
void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll exp = power(b,c,mod-1);
    ll cube=power(a,exp,mod);
    cout<<cube<<endl;
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