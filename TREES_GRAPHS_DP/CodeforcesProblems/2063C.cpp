
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
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
    vector<int> adj[n+1];
    int in[n+1] = {0};
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        in[u]++;
        in[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n==2){
        cout<<"0"<<endl;
        return;
    }
    int mx = 0;
    set<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        mx = max(mx,in[i]);
        st.insert({in[i],i});
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(in[i]==mx){
            st.erase({in[i],i});
            int curr = 0;
            curr+=in[i]-1;

            for(auto& x:adj[i]){
                // update the indegree now
                st.erase({in[x],x});
                in[x]--;
                st.insert({in[x],x});
            }
            curr+=(*st.rbegin()).first;
            ans=max(ans,curr);

            // multiple ho skte
            st.insert({in[i],i});
            for(auto& x:adj[i]){  
                // update the indegree now
                st.erase({in[x],x});
                in[x]++;
                st.insert({in[x],x});
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