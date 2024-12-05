
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

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

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(101,vector<int> (101,0));
    vector<pair<int,int>> v(n);
    int ans=0;
    int maxi=0,maxx=0,maxy=0;
    for(int i=0;i<n;i++){
        
        cin>>v[i].first>>v[i].second;
        maxi = max(maxi,v[i].first*v[i].second);
        maxx = max(maxx,v[i].first);
        maxy = max(maxy,v[i].second);
    }
    cout<<maxx*2+maxy*2<<endl;


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