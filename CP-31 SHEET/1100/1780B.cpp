
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    ll maxi=1;
    vector<ll> pre(n,0);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    // for(auto ele:pre) cout<<ele<<" ";
    for(int i=0;i<n-1;i++){
        maxi=max(maxi,gcd(pre[i],sum-pre[i]));
    }
    cout<<maxi<<endl;
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