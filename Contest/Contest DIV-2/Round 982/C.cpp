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
#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

void solve()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);
    forn(i, n) cin >> arr[i]; // Input the array

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    vector<pair<ll, ll>> vec;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        vec.push_back({arr[i]+i,i});
    }
    // if(flag){
    //     cout<<n<<endl;
    //     return;
    // }
    sort(vec.begin(),vec.end());
    set<ll> st;
    st.insert(n);
    ll maxi = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        // mp[vec[i].first] = 1;
        if (st.find(vec[i].first) != st.end())
        {
            st.insert(vec[i].first + vec[i].second);
        }
        // mp[vec[i].first + vec[i].second] = 1;
    }
    cout<<*st.rbegin()<<endl;
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
