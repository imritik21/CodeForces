
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
    ll l,r,G;
    cin>>l>>r>>G;
    if(G>r){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    pair<ll,ll> ans={-1,-1};
    l=(l+G-1)/G;
    r=r/G;
    ll maxLen = -1;
    ll res=-1;

    // ll time=30;
    for(ll i=l;i<=min(r,l+30);i++){
        for(ll j=r;j>=max(i,r-30);j--){
            if(__gcd(i,j)==1){
                if((j-i)>maxLen){
                    maxLen=(j-i);
                    res=i;
                    ans.first=res*G;
                    ans.second=(res+maxLen)*G;
                }
                break;
            }
        }
    }
    if(maxLen<0)cout<<"-1 -1"<<endl;
    else
    cout<<ans.first<<" "<<ans.second<<endl;
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