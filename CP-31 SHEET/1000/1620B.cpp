
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll w,h;
    cin>>w>>h;
    
    ll area=0;
    for(int i=0;i<4;i++){
        ll k;
        cin>>k;
        vector<ll> arr(k);
        for(int j=0;j<k;j++){
            cin>>arr[j];
        }
        // calc curr area
        ll curr = (arr.back()-arr.front())*(i<2?h:w);
        area=max(area,curr);
    }
    cout<<area<<endl;
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