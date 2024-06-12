
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
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    // finding a b and c
    ll ans=0;
    for(ll a=1;a<=x;a++){
        for(ll b=1;b<=y;b++){
            bool flag1=false;
            bool flag2=false;
            if(k%(a*b)==0) flag1=true;
            if((k/(a*b))<=z) flag2=true;

            if(flag1 && flag2){
                ll side1 = a;
                ll side2 = b;
                ll side3 = k/(a*b);

                ll distinctPlaces = (x-side1+1);
                distinctPlaces*=(y-side2+1);
                distinctPlaces*=(z-side3+1);

                ans=max(ans,distinctPlaces);
            }
        }
    }
    cout<<ans<<endl;
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