
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n;
    cin>>n;
    int seclastBit = log2(n-1);
    int lastSetBit = 1<<seclastBit;
    // cout<<lastSetBit;
    int x=0;
    for(int i=0;i<30;i++){
        x=1<<i;
        if(x>=n) break;
    }
    int lastBit= x>>1;
    // cout<<lastBit<<"\n";
    // cout<<x<<endl;
    for(int i=n-1;i>=lastBit;i--){
        cout<<i<<" ";
    }
    for(int i=0;i<lastBit;i++){
        cout<<i<<" ";
    }
    cout<<endl;
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