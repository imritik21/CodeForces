
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<int> pairs[1001];
ll gcd(ll a, ll b)
{
    while (b != 0)
    {
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
    vector<ll> idx[1001];
    for (int i = 1; i <= n; i++)
    {
        int x;cin>>x;
        idx[x].push_back(i);
    }
    
    ll sum = -1;
    for(int i=1;i<=1000;i++){
        for(int j:pairs[i]){
            if(!idx[i].empty() && !idx[j].empty()){
                sum=max(sum,idx[i].back()+idx[j].back());
            }
        }
    }
    cout << sum << endl;
}
int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j < 1001; j++)
        {
            if (__gcd(i, j) == 1)
            {
                pairs[i].push_back(j);
            }
        }
    }
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}